/*
 * Copyright (c) 2016, Xerox Corporation (Xerox) and Palo Alto Research Center, Inc (PARC)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL XEROX OR PARC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ################################################################################
 * #
 * # PATENT NOTICE
 * #
 * # This software is distributed under the BSD 2-clause License (see LICENSE
 * # file).  This BSD License does not make any patent claims and as such, does
 * # not act as a patent grant.  The purpose of this section is for each contributor
 * # to define their intentions with respect to intellectual property.
 * #
 * # Each contributor to this source code is encouraged to state their patent
 * # claims and licensing mechanisms for any contributions made. At the end of
 * # this section contributors may each make their own statements.  Contributor's
 * # claims and grants only apply to the pieces (source code, programs, text,
 * # media, etc) that they have contributed directly to this software.
 * #
 * # There is no guarantee that this section is complete, up to date or accurate. It
 * # is up to the contributors to maintain their portion of this section and up to
 * # the user of the software to verify any claims herein.
 * #
 * # Do not remove this header notification.  The contents of this section must be
 * # present in all distributions of the software.  You may only modify your own
 * # intellectual property statements.  Please provide contact information.
 *
 * - Palo Alto Research Center, Inc
 * This software distribution does not grant any rights to patents owned by Palo
 * Alto Research Center, Inc (PARC). Rights to these patents are available via
 * various mechanisms. As of January 2016 PARC has committed to FRAND licensing any
 * intellectual property used by its contributions to this software. You may
 * contact PARC at cipo@parc.com for more information or visit http://www.ccnx.org
 */
#ifndef ccnx_testrig_h
#define ccnx_testrig_h

#include <parc/algol/parc_BitVector.h>

#include "ccnxTestrig_Link.h"
#include "ccnxTestrig_Reporter.h"

struct ccnx_testrig;
typedef struct ccnx_testrig CCNxTestrig;

typedef enum {
    CCNxTestrigLinkID_LinkA = 0x01,
    CCNxTestrigLinkID_LinkB = 0x02,
    CCNxTestrigLinkID_LinkC = 0x03,
    CCNxTestrigLinkID_NULL
} CCNxTestrigLinkID;

/**
 * Retrieve the `CCNxTestrigReporter` associated with the given `CCNxTestrig`.
 *
 * @param [in] rig A `CCNxTestrig` instance.
 *
 * Example:
 * @code
 * {
 *     CCNxTestrig *rig = ...
 *     CCNxTestrigReporter *reporter = ccnxTestrig_GetReporter(rig);
 * }
 * @endcode
 */
CCNxTestrigReporter *ccnxTestrig_GetReporter(CCNxTestrig *rig);

/**
 * Retrieve the forwarder link associated with the given identity.
 *
 * @param [in] rig A `CCNxTestrig` instance.
 * @param [in] linkID A CCNxTestrigLinkID corresponding to one of the forwarder-under-test links.
 *
 * Example:
 * @code
 * {
 *     CCNxTestrig *rig = ...
 *     CCNxTestrigLink *linkA = ccnxTestrig_GetLinkByID(rig, CCNxTestrigLinkID_LinkA);
 * }
 * @endcode
 */
CCNxTestrigLink *ccnxTestrig_GetLinkByID(CCNxTestrig *rig, CCNxTestrigLinkID linkID);

/**
 * Retrieve a bit vector that encodes the links given in the variable argument list.
 *
 * @param [in] rig A `CCNxTestrig` instance.
 * @param [in] linkID A CCNxTestrigLinkID corresponding to one of the forwarder-under-test links.
 * ...
 *
 * @return A `PARCBitVector` containing the link masks indicated in the parameter list.
 *
 * Example:
 * @code
 * {
 *     CCNxTestrig *rig = ...
 *     PARCBitVector *linkVector = ccnxTestrig_GetLinkVector(rig, CCNxTestrigLinkID_LinkA);
 * }
 * @endcode
 */
PARCBitVector *ccnxTestrig_GetLinkVector(CCNxTestrig *rig, CCNxTestrigLinkID linkID, ...);

/**
 * Flush all pending messages on each of the testrig links.
 *
 * @param [in] rig A `CCNxTestrig` instance.
 *
 * Example:
 * @code
 * {
 *     CCNxTestrig *rig = ...
 *     ccnxTestrig_FlushLinks(rig);
 * }
 * @endcode
 */
void ccnxTestrig_FlushLinks(CCNxTestrig *rig);
#endif // ccnx_testrig_h
