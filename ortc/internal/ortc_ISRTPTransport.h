/*

 Copyright (c) 2014, Hookflash Inc. / Hookflash Inc.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.
 
 */

#pragma once

#include <ortc/types.h>
#include <ortc/ISRTPSDESTransport.h>

#include <ortc/internal/types.h>

#include <zsLib/Exception.h>

#include <list>

namespace ortc
{
  namespace internal
  {
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark ISRTPTransportTypes
    #pragma mark
    
    interaction ISRTPTransportTypes
    {
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark ISRTPTransport
    #pragma mark

    interaction ISRTPTransport : public ISRTPTransportTypes
    {
      virtual PUID getID() const = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark ISRTPTransportDelegate
    #pragma mark

    interaction ISRTPTransportDelegate
    {
      virtual void onSRTPTransportLifetimeRemaining(
                                                    ISRTPTransportPtr transport,
                                                    ULONG leastLifetimeRemainingPercentageForAllKeys,
                                                    ULONG overallLifetimeRemainingPercentage
                                                    ) = 0;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark ISRTPTransportSubscription
    #pragma mark

    interaction ISRTPTransportSubscription
    {
      virtual PUID getID() const = 0;

      virtual void cancel() = 0;

      virtual void background() = 0;
    };
  }
}

ZS_DECLARE_PROXY_BEGIN(ortc::internal::ISRTPTransportDelegate)
ZS_DECLARE_PROXY_TYPEDEF(ortc::internal::ISRTPTransportPtr, ISRTPTransportPtr)
ZS_DECLARE_PROXY_METHOD_3(onSRTPTransportLifetimeRemaining, ISRTPTransportPtr, ULONG, ULONG)
ZS_DECLARE_PROXY_END()

ZS_DECLARE_PROXY_SUBSCRIPTIONS_BEGIN(ortc::internal::ISRTPTransportDelegate, ortc::internal::ISRTPTransportSubscription)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_TYPEDEF(ortc::internal::ISRTPTransportPtr, ISRTPTransportPtr)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD_3(onSRTPTransportLifetimeRemaining, ISRTPTransportPtr, ULONG, ULONG)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_END()
