/*
 * Copyright (C) 2010-2013, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *
 */

#ifndef __PROJECT_RPL_WEB_CONF_H__
#define __PROJECT_RPL_WEB_CONF_H__

//#define PLATFORM_HAS_LEDS    1
//#define PLATFORM_HAS_BUTTON  1
#define PLATFORM_HAS_SERVO
//#define PLATFORM_HAS_T4_SERVO  1
#define PLATFORM_HAS_BATTERY 1

#define SICSLOWPAN_CONF_FRAG	1

/* Dont allow MCU sleeping between channel checks */
#undef RDC_CONF_MCU_SLEEP
#define RDC_CONF_MCU_SLEEP       0

/* Some platforms have weird includes. */
#undef IEEE802154_CONF_PANID

/* Increase rpl-border-router IP-buffer when using more than 64. */
#undef REST_MAX_CHUNK_SIZE
#define REST_MAX_CHUNK_SIZE    64

/* Estimate your header size, especially when using Proxy-Uri. */
/*
#undef COAP_MAX_HEADER_SIZE
#define COAP_MAX_HEADER_SIZE    70
*/

/* The IP buffer size must fit all other hops, in particular the border router. */

#undef UIP_CONF_BUFFER_SIZE
#define UIP_CONF_BUFFER_SIZE    256


/* Multiplies with chunk size, be aware of memory constraints. */
#undef COAP_MAX_OPEN_TRANSACTIONS
#define COAP_MAX_OPEN_TRANSACTIONS   4

/* Must be <= open transaction number, default is COAP_MAX_OPEN_TRANSACTIONS-1. */
/*
#undef COAP_MAX_OBSERVERS
#define COAP_MAX_OBSERVERS      2
*/

/* Filtering .well-known/core per query can be disabled to save space. */
/*
#undef COAP_LINK_FORMAT_FILTERING
#define COAP_LINK_FORMAT_FILTERING      0
*/


#endif /* PROJECT_ERBIUM_CONF_H_ */
