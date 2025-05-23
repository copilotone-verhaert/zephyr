/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Use the NRF_RTC instance for coarse radio event scheduling */
#if !defined(CONFIG_BT_CTLR_NRF_GRTC)
#define NRF_RTC NRF_RTC10
#endif /* !CONFIG_BT_CTLR_NRF_GRTC */

#undef EVENT_TIMER_ID
#define EVENT_TIMER_ID 10

#undef EVENT_TIMER
#define EVENT_TIMER _CONCAT(NRF_TIMER, EVENT_TIMER_ID)

#if !defined(CONFIG_BT_CTLR_TIFS_HW)
#undef SW_SWITCH_TIMER
#if defined(CONFIG_BT_CTLR_SW_SWITCH_SINGLE_TIMER)
#define SW_SWITCH_TIMER EVENT_TIMER
#else  /* !CONFIG_BT_CTLR_SW_SWITCH_SINGLE_TIMER */
/* TODO: Using NRF_TIMER from another domain needs DPPIC and PPIB setup */
#error "SW tIFS switching using dedicated second timer not supported yet."
#endif  /* !CONFIG_BT_CTLR_SW_SWITCH_SINGLE_TIMER */
#endif /* !CONFIG_BT_CTLR_TIFS_HW */

/* HAL abstraction of event timer prescaler value */
#define HAL_EVENT_TIMER_PRESCALER_VALUE 5U

/* NRF Radio HW timing constants
 * - provided in US and NS (for higher granularity)
 * - based on the timings configured in the HW models, which are based
 *   on the old 52832 product specification
 */

/* TXEN->TXIDLE + TXIDLE->TX (with fast Radio ramp-up mode)
 * in microseconds for LE 1M PHY.
 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_FAST_NS 41000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_FAST_US \
	HAL_RADIO_NS2US_ROUND(HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_FAST_NS)

/* TXEN->TXIDLE + TXIDLE->TX (with default Radio ramp-up mode)
 * in microseconds for LE 1M PHY.
 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_DEFAULT_NS 141000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_DEFAULT_US \
	HAL_RADIO_NS2US_ROUND(HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_DEFAULT_NS)

/* TXEN->TXIDLE + TXIDLE->TX (with default Radio ramp-up mode
 * and no HW TIFS auto-switch) in microseconds for LE 1M PHY.
 */
 /* 129.5 + 0.8 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_DEFAULT_NO_HW_TIFS_NS 130000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_DEFAULT_NO_HW_TIFS_US \
	HAL_RADIO_NS2US_ROUND( \
		HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_DEFAULT_NO_HW_TIFS_NS)

/* TXEN->TXIDLE + TXIDLE->TX (with fast Radio ramp-up mode)
 * in microseconds for LE 2M PHY.
 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_FAST_NS 40000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_FAST_US \
	HAL_RADIO_NS2US_ROUND(HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_FAST_NS)

/* TXEN->TXIDLE + TXIDLE->TX (with default Radio ramp-up mode)
 * in microseconds for LE 2M PHY.
 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_DEFAULT_NS 140000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_DEFAULT_US \
	HAL_RADIO_NS2US_ROUND(HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_DEFAULT_NS)

/* TXEN->TXIDLE + TXIDLE->TX (with default Radio ramp-up mode and
 * no HW TIFS auto-switch) in microseconds for LE 2M PHY.
 */
/* 129.5 - 0.1 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_DEFAULT_NO_HW_TIFS_NS 129000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_DEFAULT_NO_HW_TIFS_US \
	HAL_RADIO_NS2US_ROUND( \
		HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_DEFAULT_NO_HW_TIFS_NS)

/* TXEN->TXIDLE + TXIDLE->TX (with fast Radio ramp-up mode)
 * in microseconds for LE CODED PHY [S2].
 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_FAST_NS 42000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_FAST_US \
	HAL_RADIO_NS2US_ROUND(HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_FAST_NS)

/* TXEN->TXIDLE + TXIDLE->TX (with default Radio ramp-up mode)
 * in microseconds for LE 2M PHY [S2].
 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_DEFAULT_NS 132000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_DEFAULT_US \
	HAL_RADIO_NS2US_ROUND(HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_DEFAULT_NS)

/* TXEN->TXIDLE + TXIDLE->TX (with default Radio ramp-up mode and
 * no HW TIFS auto-switch) in microseconds for LE 2M PHY [S2].
 */
/* 129.5 + 2.2 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_DEFAULT_NO_HW_TIFS_NS 132000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_DEFAULT_NO_HW_TIFS_US \
	HAL_RADIO_NS2US_ROUND( \
		HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_DEFAULT_NO_HW_TIFS_NS)

/* TXEN->TXIDLE + TXIDLE->TX (with fast Radio ramp-up mode)
 * in microseconds for LE CODED PHY [S8].
 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_FAST_NS 42000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_FAST_US \
	HAL_RADIO_NS2US_ROUND(HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_FAST_NS)
/* TXEN->TXIDLE + TXIDLE->TX (with default Radio ramp-up mode)
 * in microseconds for LE 2M PHY [S8].
 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_DEFAULT_NS 122000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_DEFAULT_US \
	HAL_RADIO_NS2US_ROUND(HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_DEFAULT_NS)

/* TXEN->TXIDLE + TXIDLE->TX (with default Radio ramp-up mode and
 * no HW TIFS auto-switch) in microseconds for LE 2M PHY [S8].
 */
 /* 129.5 + 2.2 */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_DEFAULT_NO_HW_TIFS_NS 132000
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_DEFAULT_NO_HW_TIFS_US \
	HAL_RADIO_NS2US_ROUND( \
		HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_DEFAULT_NO_HW_TIFS_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with fast Radio ramp-up mode)
 * in microseconds for LE 1M PHY.
 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_FAST_NS 40000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_FAST_US \
	HAL_RADIO_NS2US_CEIL(HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_FAST_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with default Radio ramp-up mode)
 * in microseconds for LE 1M PHY.
 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_DEFAULT_NS 140000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_DEFAULT_US \
	HAL_RADIO_NS2US_CEIL(HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_DEFAULT_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with default Radio ramp-up mode and
 * no HW TIFS auto-switch) in microseconds for LE 1M PHY.
 */
/* 129.5 + 0.2 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_DEFAULT_NO_HW_TIFS_NS 129000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_DEFAULT_NO_HW_TIFS_US \
	HAL_RADIO_NS2US_CEIL( \
		HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_DEFAULT_NO_HW_TIFS_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with fast Radio ramp-up mode)
 * in microseconds for LE 2M PHY.
 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_FAST_NS 40000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_FAST_US \
	HAL_RADIO_NS2US_CEIL(HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_FAST_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with default Radio ramp-up mode)
 * in microseconds for LE 2M PHY.
 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_DEFAULT_NS 140000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_DEFAULT_US \
	HAL_RADIO_NS2US_CEIL(HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_DEFAULT_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with default Radio ramp-up mode and
 * no HW TIFS auto-switch) in microseconds for LE 2M PHY.
 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_DEFAULT_NO_HW_TIFS_NS 129000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_DEFAULT_NO_HW_TIFS_US \
	HAL_RADIO_NS2US_CEIL( \
		HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_DEFAULT_NO_HW_TIFS_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with fast Radio ramp-up mode)
 * in microseconds for LE Coded PHY [S2].
 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_FAST_NS 40000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_FAST_US \
	HAL_RADIO_NS2US_CEIL(HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_FAST_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with default Radio ramp-up mode)
 * in microseconds for LE Coded PHY [S2].
 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_DEFAULT_NS 120000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_DEFAULT_US \
	HAL_RADIO_NS2US_CEIL(HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_DEFAULT_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with default Radio ramp-up mode
 * and no HW TIFS auto-switch) in microseconds for LE Coded PHY [S2].
 */
/* 129.5 + 0.2 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_DEFAULT_NO_HW_TIFS_NS 130000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_DEFAULT_NO_HW_TIFS_US \
	HAL_RADIO_NS2US_CEIL( \
		HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_DEFAULT_NO_HW_TIFS_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with fast Radio ramp-up mode)
 * in microseconds for LE Coded PHY [S8].
 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_FAST_NS 40000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_FAST_US \
	HAL_RADIO_NS2US_CEIL(HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_FAST_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with default Radio ramp-up mode)
 * in microseconds for LE Coded PHY [S8].
 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_DEFAULT_NS 120000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_DEFAULT_US \
	HAL_RADIO_NS2US_CEIL(HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_DEFAULT_NS)

/* RXEN->RXIDLE + RXIDLE->RX (with default Radio ramp-up mode and
 * no HW TIFS auto-switch) in microseconds for LE Coded PHY [S8].
 */
/* 129.5 + 0.2 */
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_DEFAULT_NO_HW_TIFS_NS 130000
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_DEFAULT_NO_HW_TIFS_US \
	HAL_RADIO_NS2US_CEIL( \
		HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_DEFAULT_NO_HW_TIFS_NS)

#define HAL_RADIO_NRF54LX_TX_CHAIN_DELAY_US  1
#define HAL_RADIO_NRF54LX_TX_CHAIN_DELAY_NS  1000

#define HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_1M_US  9
#define HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_1M_NS  9000
#define HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_2M_US  5
#define HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_2M_NS  5000
#define HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_S2_US  30
#define HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_S2_NS  30000
#define HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_S8_US  30
#define HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_S8_NS  30000

#if defined(CONFIG_BT_CTLR_RADIO_ENABLE_FAST)
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_FAST_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_FAST_NS

#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_FAST_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_FAST_NS

#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_FAST_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_FAST_NS

#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_FAST_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_FAST_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_FAST_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_FAST_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_FAST_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_FAST_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_FAST_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_FAST_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_FAST_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_FAST_NS

#else /* !CONFIG_BT_CTLR_RADIO_ENABLE_FAST */
#if defined(CONFIG_BT_CTLR_TIFS_HW)
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_DEFAULT_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_DEFAULT_NS

#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_DEFAULT_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_DEFAULT_NS

#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_DEFAULT_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_DEFAULT_NS

#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_DEFAULT_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_DEFAULT_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_DEFAULT_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_DEFAULT_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_DEFAULT_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_DEFAULT_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_DEFAULT_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_DEFAULT_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_DEFAULT_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_DEFAULT_NS

#else /* !CONFIG_BT_CTLR_TIFS_HW */
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_DEFAULT_NO_HW_TIFS_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_DEFAULT_NO_HW_TIFS_NS

#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_DEFAULT_NO_HW_TIFS_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_DEFAULT_NO_HW_TIFS_NS

#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_DEFAULT_NO_HW_TIFS_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_DEFAULT_NO_HW_TIFS_NS

#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_US \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_DEFAULT_NO_HW_TIFS_US
#define HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_NS \
	HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_DEFAULT_NO_HW_TIFS_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_DEFAULT_NO_HW_TIFS_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_DEFAULT_NO_HW_TIFS_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_DEFAULT_NO_HW_TIFS_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_DEFAULT_NO_HW_TIFS_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_DEFAULT_NO_HW_TIFS_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_DEFAULT_NO_HW_TIFS_NS

#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_US \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_DEFAULT_NO_HW_TIFS_US
#define HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_NS \
	HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_DEFAULT_NO_HW_TIFS_NS
#endif /* !CONFIG_BT_CTLR_TIFS_HW */
#endif /* !CONFIG_BT_CTLR_RADIO_ENABLE_FAST */

/* HAL abstraction of Radio bitfields */
#define HAL_NRF_RADIO_EVENT_END                   NRF_RADIO_EVENT_END
#define HAL_RADIO_EVENTS_END                      EVENTS_END
#define HAL_RADIO_PUBLISH_END                     PUBLISH_END
#define HAL_NRF_RADIO_EVENT_PHYEND                NRF_RADIO_EVENT_PHYEND
#define HAL_RADIO_EVENTS_PHYEND                   EVENTS_PHYEND
#define HAL_RADIO_PUBLISH_PHYEND                  PUBLISH_PHYEND
#define HAL_RADIO_INTENSET_DISABLED_Msk           RADIO_INTENSET00_DISABLED_Msk
#define HAL_RADIO_SHORTS_TRX_END_DISABLE_Msk      RADIO_SHORTS_PHYEND_DISABLE_Msk
#define HAL_RADIO_SHORTS_TRX_PHYEND_DISABLE_Msk   RADIO_SHORTS_PHYEND_DISABLE_Msk
#define HAL_RADIO_CLEARPATTERN_CLEARPATTERN_Clear (1UL)

/* HAL abstraction of Radio IRQ number */
#define HAL_RADIO_IRQn                          RADIO_0_IRQn

/* SoC specific NRF_RADIO power-on reset value. Refer to Product Specification,
 * RADIO Registers section for the documented reset values.
 *
 * NOTE: Only implementation used values defined here.
 *       In the future if MDK or nRFx header include these, use them instead.
 */
#define HAL_RADIO_RESET_VALUE_DFEMODE       0x00000000UL
#define HAL_RADIO_RESET_VALUE_CTEINLINECONF 0x00002800UL
#define HAL_RADIO_RESET_VALUE_DATAWHITE     0x00890040UL

/* HAL abstraction of CCM h/w */
#define NRF_CCM                               NRF_CCM00
#define NRF_CCM_TASK_CRYPT                    NRF_CCM_TASK_START
#define EVENTS_ENDCRYPT                       EVENTS_END
#define INPTR                                 IN.PTR
#define OUTPTR                                OUT.PTR
#define MICSTATUS                             MACSTATUS
#define CCM_INTENSET_ENDCRYPT_Msk             CCM_INTENSET_END_Msk
#define CCM_INTENCLR_ENDCRYPT_Msk             CCM_INTENCLR_END_Msk
#define CCM_MODE_DATARATE_125Kbps             CCM_MODE_DATARATE_125Kbit
#define CCM_MODE_DATARATE_500Kbps             CCM_MODE_DATARATE_500Kbit
#define CCM_RATEOVERRIDE_RATEOVERRIDE_500Kbps CCM_RATEOVERRIDE_RATEOVERRIDE_500Kbit

static inline void hal_radio_reset(void)
{
	/* TODO: Add any required setup for each radio event
	 */
}

static inline void hal_radio_stop(void)
{
	/* TODO: Add any required cleanup of actions taken in hal_radio_reset()
	 */
}

static inline void hal_radio_ram_prio_setup(void)
{
	/* TODO */
}

static inline uint32_t hal_radio_phy_mode_get(uint8_t phy, uint8_t flags)
{
	uint32_t mode;

	switch (phy) {
	case BIT(0):
	default:
		mode = RADIO_MODE_MODE_Ble_1Mbit;
		break;

	case BIT(1):
		mode = RADIO_MODE_MODE_Ble_2Mbit;
		break;

#if defined(CONFIG_BT_CTLR_PHY_CODED)
	case BIT(2):
		if (flags & 0x01) {
			mode = RADIO_MODE_MODE_Ble_LR125Kbit;
		} else {
			mode = RADIO_MODE_MODE_Ble_LR500Kbit;
		}
		break;
#endif /* CONFIG_BT_CTLR_PHY_CODED */
	}

	return mode;
}

static inline int8_t hal_radio_tx_power_max_get(void)
{
	return 8; /* +8 dBm */
}

static inline int8_t hal_radio_tx_power_min_get(void)
{
	return -46; /* -46 dBm */
}

static inline int8_t hal_radio_tx_power_floor(int8_t tx_power_lvl)
{
	if (tx_power_lvl >= 8) {
		return 8;
	}

	if (tx_power_lvl >= 7) {
		return 7;
	}

	if (tx_power_lvl >= 6) {
		return 6;
	}

	if (tx_power_lvl >= 5) {
		return 5;
	}

	if (tx_power_lvl >= 4) {
		return 4;
	}

	if (tx_power_lvl >= 3) {
		return 3;
	}

	if (tx_power_lvl >= 2) {
		return 2;
	}

	if (tx_power_lvl >= 1) {
		return 1;
	}

	if (tx_power_lvl >= 0) {
		return 0;
	}

	if (tx_power_lvl >= -1) {
		return -1;
	}

	if (tx_power_lvl >= -2) {
		return -2;
	}

	if (tx_power_lvl >= -3) {
		return -3;
	}

	if (tx_power_lvl >= -4) {
		return -4;
	}

	if (tx_power_lvl >= -5) {
		return -5;
	}

	if (tx_power_lvl >= -6) {
		return -6;
	}

	if (tx_power_lvl >= -7) {
		return -7;
	}

	if (tx_power_lvl >= -8) {
		return -8;
	}

	if (tx_power_lvl >= -9) {
		return -9;
	}

	if (tx_power_lvl >= -10) {
		return -10;
	}

	if (tx_power_lvl >= -12) {
		return -12;
	}

	if (tx_power_lvl >= -14) {
		return -14;
	}

	if (tx_power_lvl >= -16) {
		return -16;
	}

	if (tx_power_lvl >= -20) {
		return -20;
	}

	if (tx_power_lvl >= -26) {
		return -26;
	}

	if (tx_power_lvl >= -40) {
		return -40;
	}

	return -46;
}

static inline uint32_t hal_radio_tx_power_value(int8_t tx_power_lvl)
{
	if (tx_power_lvl >= 8) {
		return RADIO_TXPOWER_TXPOWER_Pos8dBm;
	}

	if (tx_power_lvl >= 7) {
		return RADIO_TXPOWER_TXPOWER_Pos7dBm;
	}

	if (tx_power_lvl >= 6) {
		return RADIO_TXPOWER_TXPOWER_Pos6dBm;
	}

	if (tx_power_lvl >= 5) {
		return RADIO_TXPOWER_TXPOWER_Pos5dBm;
	}

	if (tx_power_lvl >= 4) {
		return RADIO_TXPOWER_TXPOWER_Pos4dBm;
	}

	if (tx_power_lvl >= 3) {
		return RADIO_TXPOWER_TXPOWER_Pos3dBm;
	}

	if (tx_power_lvl >= 2) {
		return RADIO_TXPOWER_TXPOWER_Pos2dBm;
	}

	if (tx_power_lvl >= 1) {
		return RADIO_TXPOWER_TXPOWER_Pos1dBm;
	}

	if (tx_power_lvl >= 0) {
		return RADIO_TXPOWER_TXPOWER_0dBm;
	}

	if (tx_power_lvl >= -1) {
		return RADIO_TXPOWER_TXPOWER_Neg1dBm;
	}

	if (tx_power_lvl >= -2) {
		return RADIO_TXPOWER_TXPOWER_Neg2dBm;
	}

	if (tx_power_lvl >= -3) {
		return RADIO_TXPOWER_TXPOWER_Neg3dBm;
	}

	if (tx_power_lvl >= -4) {
		return RADIO_TXPOWER_TXPOWER_Neg4dBm;
	}

	if (tx_power_lvl >= -5) {
		return RADIO_TXPOWER_TXPOWER_Neg5dBm;
	}

	if (tx_power_lvl >= -6) {
		return RADIO_TXPOWER_TXPOWER_Neg6dBm;
	}

	if (tx_power_lvl >= -7) {
		return RADIO_TXPOWER_TXPOWER_Neg7dBm;
	}

	if (tx_power_lvl >= -8) {
		return RADIO_TXPOWER_TXPOWER_Neg8dBm;
	}

	if (tx_power_lvl >= -9) {
		return RADIO_TXPOWER_TXPOWER_Neg9dBm;
	}

	if (tx_power_lvl >= -10) {
		return RADIO_TXPOWER_TXPOWER_Neg10dBm;
	}

	if (tx_power_lvl >= -12) {
		return RADIO_TXPOWER_TXPOWER_Neg12dBm;
	}

	if (tx_power_lvl >= -14) {
		return RADIO_TXPOWER_TXPOWER_Neg14dBm;
	}

	if (tx_power_lvl >= -16) {
		return RADIO_TXPOWER_TXPOWER_Neg16dBm;
	}

	if (tx_power_lvl >= -20) {
		return RADIO_TXPOWER_TXPOWER_Neg20dBm;
	}

#if defined(RADIO_TXPOWER_TXPOWER_Neg26dBm)
	if (tx_power_lvl >= -26) {
		return RADIO_TXPOWER_TXPOWER_Neg26dBm;
	}
#endif

#if defined(RADIO_TXPOWER_TXPOWER_Neg28dBm)
	if (tx_power_lvl >= -28) {
		return RADIO_TXPOWER_TXPOWER_Neg28dBm;
	}
#endif

	if (tx_power_lvl >= -40) {
		return RADIO_TXPOWER_TXPOWER_Neg40dBm;
	}

	return RADIO_TXPOWER_TXPOWER_Neg46dBm;
}

static inline uint32_t hal_radio_tx_ready_delay_us_get(uint8_t phy, uint8_t flags)
{
	switch (phy) {
	default:
	case BIT(0):
		return HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_US;
	case BIT(1):
		return HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_US;

#if defined(CONFIG_BT_CTLR_PHY_CODED)
	case BIT(2):
		if (flags & 0x01) {
			return HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_US;
		} else {
			return HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_US;
		}
#endif /* CONFIG_BT_CTLR_PHY_CODED */
	}
}

static inline uint32_t hal_radio_rx_ready_delay_us_get(uint8_t phy, uint8_t flags)
{
	switch (phy) {
	default:
	case BIT(0):
		return HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_US;
	case BIT(1):
		return HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_US;

#if defined(CONFIG_BT_CTLR_PHY_CODED)
	case BIT(2):
		if (flags & 0x01) {
			return HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_US;
		} else {
			return HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_US;
		}
#endif /* CONFIG_BT_CTLR_PHY_CODED */
	}
}

static inline uint32_t hal_radio_tx_chain_delay_us_get(uint8_t phy, uint8_t flags)
{
	ARG_UNUSED(phy);
	ARG_UNUSED(flags);
	return HAL_RADIO_NRF54LX_TX_CHAIN_DELAY_US;
}

static inline uint32_t hal_radio_rx_chain_delay_us_get(uint8_t phy, uint8_t flags)
{
	switch (phy) {
	default:
	case BIT(0):
		return HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_1M_US;
	case BIT(1):
		return HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_2M_US;

#if defined(CONFIG_BT_CTLR_PHY_CODED)
	case BIT(2):
		if (flags & 0x01) {
			return HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_S8_US;
		} else {
			return HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_S2_US;
		}
#endif /* CONFIG_BT_CTLR_PHY_CODED */
	}
}

static inline uint32_t hal_radio_tx_ready_delay_ns_get(uint8_t phy, uint8_t flags)
{
	switch (phy) {
	default:
	case BIT(0):
		return HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_1M_NS;
	case BIT(1):
		return HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_2M_NS;

#if defined(CONFIG_BT_CTLR_PHY_CODED)
	case BIT(2):
		if (flags & 0x01) {
			return HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S8_NS;
		} else {
			return HAL_RADIO_NRF54LX_TXEN_TXIDLE_TX_S2_NS;
		}
#endif /* CONFIG_BT_CTLR_PHY_CODED */
	}
}

static inline uint32_t hal_radio_rx_ready_delay_ns_get(uint8_t phy, uint8_t flags)
{
	switch (phy) {
	default:
	case BIT(0):
		return HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_1M_NS;
	case BIT(1):
		return HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_2M_NS;

#if defined(CONFIG_BT_CTLR_PHY_CODED)
	case BIT(2):
		if (flags & 0x01) {
			return HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S8_NS;
		} else {
			return HAL_RADIO_NRF54LX_RXEN_RXIDLE_RX_S2_NS;
		}
#endif /* CONFIG_BT_CTLR_PHY_CODED */
	}
}

static inline uint32_t hal_radio_tx_chain_delay_ns_get(uint8_t phy, uint8_t flags)
{
	ARG_UNUSED(phy);
	ARG_UNUSED(flags);
	return HAL_RADIO_NRF54LX_TX_CHAIN_DELAY_NS;
}

static inline uint32_t hal_radio_rx_chain_delay_ns_get(uint8_t phy, uint8_t flags)
{
	switch (phy) {
	default:
	case BIT(0):
		return HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_1M_NS;
	case BIT(1):
		return HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_2M_NS;

#if defined(CONFIG_BT_CTLR_PHY_CODED)
	case BIT(2):
		if (flags & 0x01) {
			return HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_S8_NS;
		} else {
			return HAL_RADIO_NRF54LX_RX_CHAIN_DELAY_S2_NS;
		}
#endif /* CONFIG_BT_CTLR_PHY_CODED */
	}
}
