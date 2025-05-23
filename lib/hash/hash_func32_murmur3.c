/*
 * Copyright (c) 2022, Meta
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stddef.h>
#include <stdint.h>
#include <zephyr/toolchain.h>
#include <zephyr/sys/util.h>

static inline uint32_t murmur_32_scramble(uint32_t k)
{
	k *= 0xcc9e2d51;
	k = (k << 15) | (k >> 17);
	k *= 0x1b873593;

	return k;
}

#define _LOOP(_GET) \
	for (; n >= sizeof(uint32_t); n -= sizeof(uint32_t), str += sizeof(uint32_t)) { \
		k =  _GET; \
		h ^= murmur_32_scramble(k); \
		h = (h << 13) | (h >> 19); \
		h = h * 5 + 0xe6546b64; \
	}

uint32_t sys_hash32_murmur3(const char *str, size_t n)
{
	uint32_t k;
	/* seed of 0 */
	uint32_t h = 0;
	const size_t len = n;

	if (IS_ALIGNED(str, sizeof(uint32_t))) {
		_LOOP(*(const uint32_t *)str);
	} else {
		_LOOP(UNALIGNED_GET((const uint32_t *)str));
	}

	for (k = 0; n != 0; --n, ++str) {
		k <<= 8;
		k |= *str;
	}

	h ^= murmur_32_scramble(k);

	h ^= len;
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;

	return h;
}
