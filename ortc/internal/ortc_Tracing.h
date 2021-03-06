/*

 Copyright (c) 2016, Hookflash Inc.
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

#include <ortc/internal/types.h>


#ifdef USE_ETW
#include "ortc_ETWTracing.h"
#include "ortc_ETWStatsReport.h"
#else

// Comment the following line to test inline versions of the same macros to test compilation
#define ORTC_USE_NOOP_EVENT_TRACE_MACROS

// NO-OP VERSIONS OF ALL TRACING MACROS
#ifdef ORTC_USE_NOOP_EVENT_TRACE_MACROS

#define EventRegisterOrtcLib()
#define EventUnregisterOrtcLib()

#define EventWriteOrtcCreate(xStr_Method, xPUID)
#define EventWriteOrtcDestroy(xStr_Method, xPUID)

#define EventWriteOrtcCertificateCreate(xStr_Method, xPUID, xStr_KeyGenAlgorithm, xStr_Name, xStr_NamedCurve, xsize_t_KeyLength, xsize_t_RandomBits, xStr_PublicExponenetLength, xlong_long_LifetimeInSeconds, xlong_long_NotBeforeWindowInSeconds, xlong_long_ExpiresInSecondsSinceEpoch)
#define EventWriteOrtcCertificateDestroy(xStr_Method, xPUID)
#define EventWriteOrtcCertificateGeneratedEventFired(xStr_Method, xPUID, xBool_Success)
#define EventWriteOrtcCertificateFingerprint(xStr_Method, xPUID, xStr_FingerprintAlgorithm, xStr_FingerprintValue)

#define EventWriteOrtcDataChannelCreate(xStr_Method, xPUID, xPUID_DataTransport, xStr_Parameters, xBool_Incoming, xWORD_SessionID)
#define EventWriteOrtcDataChannelDestroy(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelClose(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelCancel(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelStep(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcDataChannelErrorEventFired(xStr_Method, xPUID, xWORD_Error, xStr_Reason)

#define EventWriteOrtcDataChannelSendControlOpen(xStr_Method, xPUID, xBYTE_MessageType, xBYTE_ChannelType, xWORD_Priority, xDWORD_ReliabilityParameter, xWORD_LabelLength, xWORD_ProtocolLength, xStr_Label, xStr_Protocol)
#define EventWriteOrtcDataChannelSendControlAck(xStr_Method, xPUID, xBYTE_MessageType)

#define EventWriteOrtcDataChannelBufferedAmountLowThresholdChanged(xStr_Method, xPUID, xsize_t_NewThreshold, xsize_t_OldThreshold, xsize_t_OutgoingBufferFillSize, xBool_BufferedAmountLowThresholdFired)

#define EventWriteOrtcDataChannelSendString(xStr_Method, xPUID, xStr_Data)
#define EventWriteOrtcDataChannelSendBinary(xStr_Method, xPUID, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcDataChannelOutgoingBufferPacket(xStr_Method, xPUID, xUInt_Type, xWORD_SessionID, xBool_Ordered, xlong_long_MaxPacketLifetimeInMilliseconds, xBool_HasMaxRetransmits, xDWORD_MaxRetransmits, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcDataChannelOutgoingBufferPacketDelivered(xStr_Method, xPUID, xUInt_Type, xWORD_SessionID, xBool_Ordered, xlong_long_MaxPacketLifetimeInMilliseconds, xBool_HasMaxRetransmits, xDWORD_MaxRetransmits, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcDataChannelReceivedControlOpen(xStr_Method, xPUID, xBool_Incoming, xBYTE_MessageType, xBYTE_ChannelType, xWORD_Priority, xDWORD_ReliabilityParameter, xWORD_LabelLength, xWORD_ProtocolLength, xStr_Label, xStr_Protocol)
#define EventWriteOrtcDataChannelReceivedControlAck(xStr_Method, xPUID, xBYTE_MessageType)

#define EventWriteOrtcDataChannelMessageFiredEvent(xStr_Method, xPUID, xUInt_Type, xWORD_SessionID, xWORD_SequenceNumber, xDWORD_Timestamp, xInt_Flags, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcDataChannelSCTPTransportDeliverOutgoingPacket(xStr_Method, xPUID, xUInt_Type, xWORD_SessionID, xBool_Ordered, xlong_long_MaxPacketLifetimeInMilliseconds, xBool_HasMaxRetransmits, xDWORD_MaxRetransmits, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcDataChannelSCTPTransportRequestShutdown(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelSCTPTransportRequestNotifyClosed(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelSCTPTransportStateChanged(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelSCTPTransportSendReady(xStr_Method, xPUID)
#define EventWriteOrtcDataChannelSCTPTransportSendReadyFailure(xStr_Method, xPUID, xWORD_Error, xStr_Reason)
#define EventWriteOrtcDataChannelSCTPTransportReceivedIncomingPacket(xStr_Method, xPUID, xUInt_Type, xWORD_SessionID, xWORD_SequenceNumber, xDWORD_Timestamp, xInt_Flags, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcDtlsTransportCreate(xStr_Method, xPUID, xPUID_IceTransport, xStr_Component, xsize_t_MaxPendingDTLSBuffer, xsize_t_MaxPendingRTPPackets, xsize_t_TotalCertificates)
#define EventWriteOrtcDtlsTransportDestroy(xStr_Method, xPUID)
#define EventWriteOrtcDtlsTransportInitialization(xStr_Method, xPUID, xPUID_IceTransport, xPUID_RtpListener, xsize_t_TotalCiphers, xsize_t_TotalFingerprints)
#define EventWriteOrtcDtlsTransportStep(xStr_Method, xPUID)
#define EventWriteOrtcDtlsTransportCancel(xStr_Method, xPUID)

#define EventWriteOrtcDtlsTransportInitializationInstallCipher(xStr_Method, xPUID, xStr_Cipher)
#define EventWriteOrtcDtlsTransportInitializationInstallFingerprint(xStr_Method, xPUID, xStr_Algorithm, xStr_Value, xBool_IsLocal)

#define EventWriteOrtcDtlsTransportStart(xStr_Method, xPUID, xStr_Role, xsize_t_TotalFingerprints)
#define EventWriteOrtcDtlsTransportStop(xStr_Method, xPUID)

#define EventWriteOrtcDtlsTransportRoleSet(xStr_Method, xPUID, xStr_Role)

#define EventWriteOrtcDtlsTransportReceivedPacket(xStr_Method, xPUID, xUInt_ViaTransport, xBool_IsDtlsPacket, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcDtlsTransportReceivedStunPacket(xStr_Method, xPUID, xUInt_ViaTransport)

#define EventWriteOrtcDtlsTransportForwardingEncryptedPacketToSrtpTransport(xStr_Method, xPUID, xPUID_SrtpTransportObjectID, xUInt_ViaTransport, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcDtlsTransportForwardingPacketToDataTransport(xStr_Method, xPUID, xPUID_DataTransportObjectID, xUInt_ViaTransport, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcDtlsTransportForwardingPacketToRtpListener(xStr_Method, xPUID, xPUID_RtpListenerObjectID, xUInt_ViaTransport, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcDtlsTransportSendRtpPacket(xStr_Method, xPUID, xUInt_SendOverComponent, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcDtlsTransportSendDataPacket(xStr_Method, xPUID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcDtlsTransportForwardDataPacketToIceTransport(xStr_Method, xPUID, xPUID_IceTransportObjectID, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcDtlsTransportSendEncryptedRtpPacket(xStr_Method, xPUID, xPUID_IceTransportObjectID, xUInt_SendOverComponent, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcDtlsTransportInternalTimerEventFired(xStr_Method, xPUID, xPUID_TimerObjectID)
#define EventWriteOrtcDtlsTransportInternalIceStateChangeEventFired(xStr_Method, xPUID, xPUID_IceTransportObjectID, xStr_State)
#define EventWriteOrtcDtlsTransportInternalSrtpTransportLifetimeRemainingEventFired(xStr_Method, xPUID, xPUID_SrtpTransportObjectID, xULONG_LeastLifetimeRemainingPercentageForAllKeys, xULONG_OverallLifetimeRemainingPercentage)

#define EventWriteOrtcDtlsTransportStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcDtlsTransportErrorEventFired(xStr_Method, xPUID, xWORD_Error, xStr_Reason)

#define EventWriteOrtcDtlsTransportSrtpKeyingMaterialSetup(xStr_Method, xPUID, xPUID_SecureTransportObjectID, xStr_Direction, xStr_Cipher, xsize_t_KeyingMaterialBufferSizeInBytes, xPtr_KeyingMaterialBuffer)

#define EventWriteOrtcIceGathererCreate(xStr_Method, xPUID, xPUID_GethererRouterObjectID, xStr_UsernameFragment, xStr_Password, xBool_CreateTCPCandidates, xBool_ContinousGathering, xsize_t_TotalInterfacePolicies, xsize_t_TotalIceServers, xlong_long_ReflexiveInactivityTimeInSeconds, xlong_long_RelayInactivityTimeInSeoncds, xlong_long_MaxBufferingTimeInSeconds, xlong_long_RecheckIPsInSeconds, xsize_t_MaxTotalBuffers, xsize_t_MaxTCPBufferingSizePendingConnectionInBytes, xsize_t_MaxTCPBufferingSizeConnectedInBytes, xBool_GatherPassiveTCP)
#define EventWriteOrtcIceGathererDestroy(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererStep(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererCancel(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererCreatedAssociateGatherer(xStr_Method, xPUID, xPUID_AssociatedGathererObjectID)

#define EventWriteOrtcIceGathererInitializeInstallInterfaceNameMapping(xStr_Method, xPUID, xStr_InterfaceNameRegularExpresssion, xStr_InterfaceType, xULONG_OrderIndex)
#define EventWriteOrtcIceGathererInitializeInstallPreference(xStr_Method, xPUID, xStr_PreferenceType, xStr_Preference, xStr_SubPreference, xDWORD_PreferenceValue)

#define EventWriteOrtcIceGathererGather(xStr_Method, xPUID, xBool_ContinuousGathering, xsize_t_TotalInterfacePolicies, xsize_t_TotalIceServers)

#define EventWriteOrtcIceGathererStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcIceGathererErrorEventFired(xStr_Method, xPUID, xWORD_Error, xStr_Reason)

#define EventWriteOrtcIceGathererAddCandidateEventFired(xStr_Method, xPUID, xStr_LocalHash, xStr_NotifyHash, xStr_InterfaceType, xStr_Foundation, xWORD_Component, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort)
#define EventWriteOrtcIceGathererRemoveCandidateEventFired(xStr_Method, xPUID, xStr_LocalHash, xStr_NotifyHash, xStr_InterfaceType, xStr_Foundation, xWORD_Component, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort)
#define EventWriteOrtcIceGathererFilterCandidateEventFired(xStr_Method, xPUID, xUInt_FilterPolicy, xStr_BoundIP, xStr_InterfaceType, xStr_Foundation, xWORD_Component, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort)

#define EventWriteOrtcIceGathererInstallIceTransport(xStr_Method, xPUID, xPUID_IceTransportObjectID, xStr_RemoteUsernameFragment)
#define EventWriteOrtcIceGathererRemoveIceTransport(xStr_Method, xPUID, xPUID_IceTransportObjectID)
#define EventWriteOrtcIceGathererInternalIceTransportStateChangedEventFired(xStr_Method, xPUID, xPUID_IceTransportObjectID)

#define EventWriteOrtcIceGathererRemovetAllIceTransportRelatedRoutes(xStr_Method, xPUID, xPUID_IceTransportObjectID)
#define EventWriteOrtcIceGathererSendIceTransportPacket(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceGathererSendIceTransportPacketFailed(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcIceGathererSendIceTransportPacketViaUdp(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_HostPortObjectID, xStr_RemoteIP, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceGathererSendIceTransportPacketViaTcp(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_TcpPortObjectID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceGathererSendIceTransportPacketViaTurn(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_TurnObjectID, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcIceGathererDeliverIceTransportIncomingPacket(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_RouterRouteID, xBool_WasBuffered, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceGathererBufferIceTransportIncomingPacket(xStr_Method, xPUID, xPUID_RouterRouteID, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcIceGathererDeliverIceTransportIncomingStunPacket(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_RouterRouteID, xBool_WasBuffered)
#define EventWriteOrtcIceGathererBufferIceTransportIncomingStunPacket(xStr_Method, xPUID, xPUID_RouterRouteID)
#define EventWriteOrtcIceGathererErrorIceTransportIncomingStunPacket(xStr_Method, xPUID, xPUID_IceTransportObjectID, xPUID_RouteID, xPUID_RouterRouteID)

#define EventWriteOrtcIceGathererDisposeBufferedIceTransportIncomingPacket(xStr_Method, xPUID, xPUID_RouterRouteID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceGathererDisposeBufferedIceTransportIncomingStunPacket(xStr_Method, xPUID, xPUID_RouterRouteID)

#define EventWriteOrtcIceGathererTurnSocketReceivedPacket(xStr_Method, xPUID, xPUID_TurnSocketObjectID, xStr_RemoteIP, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceGathererTurnSocketSendPacket(xStr_Method, xPUID, xPUID_TurnSocketObjectID, xStr_RemoteIP, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcIceGathererInstallQuickRoute(xStr_Method, xPUID, xPtr_Candidate, xStr_IPAddress, xPUID_RouteID)
#define EventWriteOrtcIceGathererRemoveQuickRoute(xStr_Method, xPUID, xPtr_Candidate, xStr_IPAddress, xPUID_RouteID)
#define EventWriteOrtcIceGathererSearchQuickRoute(xStr_Method, xPUID, xPtr_Candidate, xStr_IPAddress, xBool_Found)

#define EventWriteOrtcIceGathererInternalWakeEventFired(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererInternalDnsLoookupCompleteEventFired(xStr_Method, xPUID, xPUID_DnsQueryObjectID)
#define EventWriteOrtcIceGathererInternalTimerEventFired(xStr_Method, xPUID, xPUID_TimerObjectID, xStr_TimerType, xPUID_RelatedObjectID)
#define EventWriteOrtcIceGathererInternalLikelyReflexiveActivityEventFired(xStr_Method, xPUID, xPUID_RouteID, xPUID_RouterRouteID)

#define EventWriteOrtcIceGathererInternalSocketReadReadyEventFired(xStr_Method, xPUID, xRelatedObjectID)
#define EventWriteOrtcIceGathererInternalSocketWriteReadyEventFired(xStr_Method, xPUID, xRelatedObjectID)
#define EventWriteOrtcIceGathererInternalSocketExceptionEventFired(xStr_Method, xPUID, xRelatedObjectID)

#define EventWriteOrtcIceGathererInternalBackOffTimerStateChangedEventFired(xStr_Method, xPUID, xPUID_BackOffTimerObjectID, xStr_State)

#define EventWriteOrtcIceGathererInternalStunDiscoverySendPacket(xStr_Method, xPUID, xPUID_StunDiscoveryObjectID, xStr_DestinationIP, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceGathererInternalStunDiscoveryCompleteEventFired(xStr_Method, xPUID, xPUID_StunDiscoveryObjectID, xPUID_HostPortObjectID, xStr_MappedIP)

#define EventWriteOrtcIceGathererInternalTurnSocketStateChangeEventFired(xStr_Method, xPUID, xPUID_TurnSocketObjectID, xStr_State)

#define EventWriteOrtcIceGathererResolveHostIP(xStr_Method, xPUID, xPUID_DnsQueryObjectID, xStr_HostName)
#define EventWriteOrtcIceGathererResolveFoundHostIP(xStr_Method, xPUID, xStr_HostIP, xStr_HostName, xStr_InterfaceName, xULONG_AdapterSpecific)

#define EventWriteOrtcIceGathererPendingResolveHostIP(xStr_Method, xPUID, xStr_ProfileName, xStr_HostName, xStr_IP)

#define EventWriteOrtcIceGathererHostPortCreate(xStr_Method, xPUID, xPUID_HostPortObjectID, xStr_HostIP)
#define EventWriteOrtcIceGathererHostPortDestroy(xStr_Method, xPUID, xPUID_HostPortObjectID, xStr_HostIP)
#define EventWriteOrtcIceGathererHostPortBind(xStr_Method, xPUID, xPUID_HostPortObjectID, xStr_HostIP, Str_ProtocolType, xBool_Success)
#define EventWriteOrtcIceGathererHostPortClose(xStr_Method, xPUID, xPUID_HostPortObjectID, xStr_HostIP, Str_ProtocolType)

#define EventWriteOrtcIceGathererReflexivePortCreate(xStr_Method, xPUID, xPUID_ReflexivePortObjectID, xStr_Server)
#define EventWriteOrtcIceGathererReflexivePortDestroy(xStr_Method, xPUID, xPUID_ReflexivePortObjectID, xStr_Server)
#define EventWriteOrtcIceGathererReflexivePortFoundMapped(xStr_Method, xPUID, xPUID_ReflexivePortObjectID, xStr_MappedIP)

#define EventWriteOrtcIceGathererRelayPortCreate(xStr_Method, xPUID, xPUID_RelayPortObjectID, xStr_Server, xStr_Username, xStr_Credential, xStr_CredentialType)
#define EventWriteOrtcIceGathererRelayPortDestroy(xStr_Method, xPUID, xPUID_RelayPortObjectID, xStr_Server)
#define EventWriteOrtcIceGathererRelayPortFoundIP(xStr_Method, xPUID, xPUID_RelayPortObjectID, xStr_CandidateType, xStr_IP)

#define EventWriteOrtcIceGathererTcpPortCreate(xStr_Method, xPUID, xPUID_TcpPortObjectID, xStr_RemoteIP)
#define EventWriteOrtcIceGathererTcpPortDestroy(xStr_Method, xPUID, xPUID_TcpPortObjectID, xStr_RemoteIP)

#define EventWriteOrtcIceGathererUdpSocketPacketReceivedFrom(xStr_Method, xPUID, xStr_FromIP, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceGathererUdpSocketPacketForwardingToTurnSocket(xStr_Method, xPUID, xStr_FromIP, xBool_IsStun, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceGathererUdpSocketPacketSentTo(xStr_Method, xPUID, xStr_BoundIP, xStr_ToIP, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcIceGathererTcpSocketPacketReceivedFrom(xStr_Method, xPUID, xStr_FromIP, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceGathererTcpSocketSentOutgoing(xStr_Method, xPUID, xStr_FromIP, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcIceGathererRouteTrace(xStr_Method, xStr_CallingMethod, xStr_Message, xPUID_IceGathererRouteID, xPUID_IceGathererObjectID, xlong_long_LastUsedInMillisecondsSinceEpoch, xPUID_IceTransportObjectID, xPUID_HostPortObjectID, xPUID_RelayPortObjectID, xPUID_TcpPortObjectID, xStr_LocalInterfaceType, xStr_LocalFoundation, xDWORD_LocalPriority, xDWORD_LocalUnfreezePriority, xStr_LocalProtocol, xStr_LocalIP, xWORD_LocalPort, xStr_LocalCandidateType, xStr_LocalTcpType, xStr_LocalRelatedAddress, xWORD_LocalRelatedPort)

#define EventWriteOrtcIceGathererRouterCreate(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererRouterDestroy(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererRouterCancel(xStr_Method, xPUID)
#define EventWriteOrtcIceGathererRouterInternalEvent(xStr_Method, xPUID, xStr_Event, xStr_CandidateHash, xStr_LocalCandidateIP, xWORD_LocalCandidatePort, xStr_RemoteIP)

#define EventWriteOrtcIceGathererRouterRouteTrace(xStr_Method, xStr_CallingMethod, xStr_Message, xPUID_IceGathererRouterRouteID, xStr_LocalInterfaceType, xStr_LocalFoundation, xDWORD_LocalPriority, xDWORD_LocalUnfreezePriority, xStr_LocalProtocol, xStr_LocalIP, xWORD_LocalPort, xStr_LocalCandidateType, xStr_LocalTcpType, xStr_LocalRelatedAddress, xWORD_LocalRelatedPort, xStr_RemoteIP)

#define EventWriteOrtcIceTransportCreate(xStr_Method, xPUID, xPUID_IceGathererObjectID, xPUID_IceGathererRouterObjectID, xlong_long_NoPacketReceivedRecheckTimeInSeconds, xlong_long_ExpireRouteInSeconds, xBool_TestLowerPreferenceCandidatePairs, xBool_BlacklistConsent, xlong_long_KeepWarmTimeBaseInMilliseconds, xlong_long_KeepWarmTimeRandomAddTimeInMilliseconds, xsize_t_MaxBufferedPackets, xQWORD_ConflictResolver)
#define EventWriteOrtcIceTransportDestroy(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportStep(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportCancel(xStr_Method, xPUID)

#define EventWriteOrtcIceTransportRouteStateTrackerStateCountChange(xStr_Method, xPUID_IceTransportObjectID, xStr_State, xsize_t_Value)

#define EventWriteOrtcIceTransportStart(xStr_Method, xPUID, xPUID_IceGathererObjectID, xBool_RemoteUseCandidateFreezePriority, xStr_RemoteUsernameFragment, xStr_RemotePassword, xBool_IceLite, xStr_RemoteParametersHash, xStr_OldRemoteParametersHash, xBool_HasRemoteUsernameFragment)
#define EventWriteOrtcIceTransportCreateAssociatedTransport(xStr_Method, xPUID, xPUID_AssociatedTransportObjectID)

#define EventWriteOrtcIceTransportAddRemoteCandidate(xStr_Method, xPUID, xStr_Hash, xStr_InterfaceType, xStr_Foundation, xWORD_Component, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort, xBool_PreviouslyAdded)
#define EventWriteOrtcIceTransportAddRemoteCandidateComplete(xStr_Method, xPUID, xWORD_Component)
#define EventWriteOrtcIceTransportRemoveRemoteCandidate(xStr_Method, xPUID, xStr_Hash, xStr_InterfaceType, xStr_Foundation, xWORD_Component, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort, xBool_WasKnownPreviously)
#define EventWriteOrtcIceTransportRemoveRemoteCandidateComplete(xStr_Method, xPUID, xWORD_Component)

#define EventWriteOrtcIceTransportKeepWarm(xStr_Method, xPUID, xStr_Reason, xStr_CandidatePairHash, xBool_KeepWarm)

#define EventWriteOrtcIceTransportStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcIceTransportErrorEventFired(xStr_Method, xPUID, xWORD_Error, xStr_Reason)
#define EventWriteOrtcIceTransportCandidatePairChangedEventFired(xStr_Method, xPUID, xPUID_RouteID)

#define EventWriteOrtcIceTransportRouteTrace(xStr_Method, xStr_CallingMethod, xStr_Message, xPUID_TransportRouteID, xPUID_IceTransportObjectID, xStr_CandidatePairHash, xStr_LocalInterfaceType, xStr_LocalFoundation, xDWORD_LocalPriority, xDWORD_LocalUnfreezePriority, xStr_LocalProtocol, xStr_LocalIP, xWORD_LocalPort, xStr_LocalCandidateType, xStr_LocalTcpType, xStr_LocalRelatedAddress, xWORD_LocalRelatedPort, xStr_RemoteInterfaceType, xStr_RemoteFoundation, xDWORD_RemotePriority, xDWORD_RemoteUnfreezePriority, xStr_RemoteProtocol, xStr_RemoteIP, xWORD_RemotePort, xStr_RemoteCandidateType, xStr_RemoteTcpType, xStr_RemoteRelatedAddress, xWORD_RemoteRelatedPort, xPUID_IceGathererRouteID, xQWORD_PendingPriority, xlong_long_LastReceivedCheckTimeInMillisecondsSinceEpoch, xlong_long_LastSentCheckTimeInMillisecondsSinceEpoch, xlong_long_LastReceivedMediaTimeInMillisecondsSinceEpoch, xlong_long_LastReceivedResponseTimeInMillisecondsSinceEpoch, xBool_Prune, xBool_KeepWarm, xPUID_OutgoingCheckStunRequesterObjectID, xPUID_NextKeepWarmTimerObjectID, xBool_FrozenPromise, xsize_t_TotalDependentPromises, xlong_long_LastRoundTripCheckInMillisecondsSinceEpoch, xlong_long_LastRoundTripMeasurementInMilliseconds)

#define EventWriteOrtcIceTransportReceivedPacketFromGatherer(xStr_Method, xPUID, xPUID_RouterRouteID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceTransportReceivedStunPacketFromGatherer(xStr_Method, xPUID, xPUID_RouterRouteID)
#define EventWriteOrtcIceTransportRetryReceivedStunPacketFromGatherer(xStr_Method, xPUID, xPUID_RouterRouteID)

#define EventWriteOrtcIceTransportBufferingIncomingPacket(xStr_Method, xPUID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceTransportDisposingBufferedIncomingPacket(xStr_Method, xPUID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceTransportDeliveringBufferedIncomingPacketToSecureTransport(xStr_Method, xPUID, xPUID_SecureTransportObjectID, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcIceTransportDeliveringIncomingPacketToSecureTransport(xStr_Method, xPUID, xPUID_SecureTransportObjectID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceTransportDeliveringIncomingStunPacketToSecureTransport(xStr_Method, xPUID, xPUID_SecureTransportObjectID)

#define EventWriteOrtcIceTransportInstallFoundation(xStr_Method, xPUID, xStr_LocalFoundation, xStr_RemoteFoundation, xsize_t_TotalRoutes)
#define EventWriteOrtcIceTransportRemoveFoundation(xStr_Method, xPUID, xStr_LocalFoundation, xStr_RemoteFoundation, xsize_t_TotalRoutes)
#define EventWriteOrtcIceTransportInstallFoundationDependencyFreezePromise(xStr_Method, xPUID, xStr_LocalFoundation, xStr_RemoteFoundation)

#define EventWriteOrtcIceTransportSecureTransportSendPacket(xStr_Method, xPUID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceTransportForwardSecureTransportPacketToGatherer(xStr_Method, xPUID, xPUID_IceGathererObjectID, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcIceTransportSendStunPacket(xStr_Method, xPUID, xPUID_IceGathererObjectID, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcIceTransportInternalControllerAttachedEventFired(xStr_Method, xPUID, xPUID_IceTransportControllerObjectID)
#define EventWriteOrtcIceTransportInternalControllerDetachedEventFired(xStr_Method, xPUID, xPUID_IceTransportControllerObjectID)

#define EventWriteOrtcIceTransportInternalSecureTransportAttachedEventFired(xStr_Method, xPUID, xPUID_SecureTransportObjectID)
#define EventWriteOrtcIceTransportInternalSecureTransportDetachedEventFired(xStr_Method, xPUID, xPUID_SecureTransportObjectID)

#define EventWriteOrtcIceTransportInternalWarmRoutesChangedEventFired(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportInternalDeliveryPendingPacketsEventFired(xStr_Method, xPUID)

#define EventWriteOrtcIceTransportInternalWakeEventFired(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportInternalTimerEventFired(xStr_Method, xPUID, xPUID_TimerObjectID, xStr_TimerType)

#define EventWriteOrtcIceTransportInternalUnfrozenPromiseEventFired(xStr_Method, xPUID, xPUID_RouteID)

#define EventWriteOrtcIceTransportInternalGathererStateChangedEventFired(xStr_Method, xPUID, xPUID_IceGathererObjectID, xStr_State)
#define EventWriteOrtcIceTransportInternalGathererAddLocalCandidateEventFired(xStr_Method, xPUID, xPUID_IceGathererObjectID, xStr_InterfaceType, xStr_Foundation, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort)
#define EventWriteOrtcIceTransportInternalGathererAddLocalCandidateCompleteEventFired(xStr_Method, xPUID, xPUID_IceGathererObjectID, WORD xWORD_Component)
#define EventWriteOrtcIceTransportInternalGathererRemoveLocalCandidateEventFired(xStr_Method, xPUID, xPUID_IceGathererObjectID, xStr_InterfaceType, xStr_Foundation, xDWORD_Priority, xDWORD_UnfreezePriority, xStr_Protocol, xStr_IP, xWORD_Port, xStr_CandidateType, xStr_TcpType, xStr_RelatedAddress, xWORD_RelatedPort)

#define EventWriteOrtcIceTransportInternalStunRequesterCreate(xStr_Method, xPUID, xPUID_StunRequesterObjectID)
#define EventWriteOrtcIceTransportInternalStunRequesterSendPacket(xStr_Method, xPUID, xPUID_StunRequesterObjectID, xStr_DestinationIP, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcIceTransportInternalStunRequesterReceivedResponse(xStr_Method, xPUID, xPUID_StunRequesterObjectID, xStr_FromIP)
#define EventWriteOrtcIceTransportInternalStunRequesterReceivedResponseMismatch(xStr_Method, xPUID, xPUID_StunRequesterObjectID, xStr_FromIP, xStr_ExpectingIP)
#define EventWriteOrtcIceTransportInternalStunRequesterTimedOut(xStr_Method, xPUID, xPUID_StunRequesterObjectID)

#define EventWriteOrtcIceTransportInternalRoleConflictDetectedEventFired(xStr_Method, xPUID, xStr_NewRole, xStr_Reason)

#define EventWriteOrtcIceTransportControllerCreate(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportControllerDestroy(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportControllerCancel(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportControllerStep(xStr_Method, xPUID)

#define EventWriteOrtcIceTransportControllerInternalWakeEventFired(xStr_Method, xPUID)
#define EventWriteOrtcIceTransportControllerInternalTransportAttachedEventFired(xStr_Method, xPUID, xPUID_IceTransportObjectID, xsize_t_AttachedOrderID, xBool_HasInsertIndex, xsize_t_InsertIndex)
#define EventWriteOrtcIceTransportControllerInternalTransportDetachedEventFired(xStr_Method, xPUID, xPUID_IceTransportObjectID, xsize_t_DetachedOrderID)

#define EventWriteOrtcIceTransportControllerWaitUntilUnfrozen(xStr_Method, xPUID, xPUID_IceTransportObjectID, xStr_LocalFoundation, xStr_RemoteFoundation)
#define EventWriteOrtcIceTransportControllerNoNeedToWaitUntilUnfrozen(xStr_Method, xPUID, xPUID_IceTransportObjectID, xStr_LocalFoundation, xStr_RemoteFoundation)

#define EventWriteOrtcRtpListenerCreate(xStr_Method, xPUID, xPUID_RtpTransport, xsize_t_MaxBufferedRtpPackets, xlong_long_MaxRtpPacketAgeInSeconds, xsize_t_MaxBufferedRtcpPackets, xlong_long_AmbigousPayloadMappingMinDifferenceInMilliseconds, xlong_long_SsrcTableExpiresInSeconds, xlong_long_UnhandledEventsExpiresInSeconds)
#define EventWriteOrtcRtpListenerDestroy(xStr_Method, xPUID)
#define EventWriteOrtcRtpListenerCancel(xStr_Method, xPUID)
#define EventWriteOrtcRtpListenerStep(xStr_Method, xPUID)
#define EventWriteOrtcRtpListenerFindMapping(xStr_Method, xPUID, xStr_MuxID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcRtpListenerFoundMappingByMuxID(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xStr_MuxID)
#define EventWriteOrtcRtpListenerFoundMappingBySsrc(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xDWORD_Ssrc)
#define EventWriteOrtcRtpListenerFoundMappingByPayloadType(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xBYTE_PayloadType)

#define EventWriteOrtcRtpListenerStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcRtpListenerErrorEventFired(xStr_Method, xPUID, xWORD_ErrorCode, xStr_Reason)
#define EventWriteOrtcRtpListenerUnhandledEventFired(xStr_Method, xPUID, xStr_MuxID, xStr_Rid, xDWORD_Ssrc, xBYTE_PayloadType)

#define EventWriteOrtcRtpListenerRegisterHeaderExtension(xStr_Method, xPUID, xPUID_RegisterForObject, xStr_ExtensionURI, xunsigned_short_LocalID, xBool_Encrypted, xsize_t_TotalReferences)
#define EventWriteOrtcRtpListenerUnregisterHeaderExtension(xStr_Method, xPUID, xPUID_RegisterForObject, xStr_ExtensionURI, xunsigned_short_LocalID, xBool_Encrypted, xsize_t_TotalReferences)

#define EventWriteOrtcRtpListenerReceivedIncomingPacket(xStr_Method, xPUID, xUInt_ViaComponent, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcRtpListenerBufferIncomingPacket(xStr_Method, xPUID, xUInt_ViaComponent, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcRtpListenerForwardIncomingPacket(xStr_Method, xPUID, xPUID_SenderOrReceiverObjectID, xUInt_ViaComponent, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcRtpListenerDisposeBufferedIncomingPacket(xStr_Method, xPUID, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcRtpListenerRegisterReceiver(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xPUID_OrderID, xStr_Kind)
#define EventWriteOrtcRtpListenerUnregisterReceiver(xStr_Method, xPUID, xPUID_RtpReceiverObjectID)

#define EventWriteOrtcRtpListenerRegisterSender(xStr_Method, xPUID, xPUID_RtpSenderObjectID)
#define EventWriteOrtcRtpListenerUnregisterSender(xStr_Method, xPUID, xPUID_RtpSenderObjectID)

#define EventWriteOrtcRtpListenerInternalWakeEventFired(xStr_Method, xPUID)
#define EventWriteOrtcRtpListenerInternalTimerEventFired(xStr_Method, xPUID, xPUID_TimerObjectID, xStr_TimerType)

#define EventWriteOrtcRtpListenerSsrcTableEntryAdded(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xDWORD_Ssrc, xlong_long_LastUsageSinceEpochInSeconds, xStr_MuxID)
#define EventWriteOrtcRtpListenerSsrcTableEntryRemoved(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xDWORD_Ssrc, xlong_long_LastUsageSinceEpochInSeconds, xStr_MuxID, xStr_Reason)
#define EventWriteOrtcRtpListenerSsrcTableEntryUpdated(xStr_Method, xPUID, xPUID_RtpReceiverObjectID, xDWORD_Ssrc, xlong_long_LastUsageSinceEpochInSeconds, xStr_MuxID)

#define EventWriteOrtcRtpMediaEngineCreate(xStr_Method, xPUID)
#define EventWriteOrtcRtpMediaEngineDestroy(xStr_Method, xPUID)

#define EventWriteOrtcRtpReceiverCreate(xStr_Method, xPUID, xStr_Kind, xPUID_RtpListenerObjectID, xPUID_RtpTransportObjectID, xPUID_RtcpTransportObjectID, xPUID_MediaStreamTrackObjectID, xsize_t_MaxBufferedRtpPackets, xlong_long_MaxRTPPacketAgeInSeconds, xlong_long_LockAfterSwitchTimeInMilliseconds, xlong_long_AmbigousPayloadMappingMinDifferenceInMilliseconds, xlong_long_SSRCTableExpiresInSeconds, xlong_long_ContributingSourcesExpiry)
#define EventWriteOrtcRtpReceiverDestroy(xStr_Method, xPUID)
#define EventWriteOrtcRtpReceiverStep(xStr_Method, xPUID)
#define EventWriteOrtcRtpReceiverCancel(xStr_Method, xPUID)

#define EventWriteOrtcRtpReceiverSetTransport(xStr_Method, xPUID, xPUID_RtpListenerObjectID, xPUID_RtpTransportObjectID, xPUID_RtcpTransportObjectID)

#define EventWriteOrtcRtpReceiverReportRtcpFeedback(xStr_Method, xStr_Type, xStr_Parameter)
#define EventWriteOrtcRtpReceiverReportCodec(xStr_Method, xStr_Name, xStr_Kind, xunsigned_long_CodecRate, xBYTE_PreferredPayloadType, xunsigned_long_PTime, xunsigned_long_MaxPTime, xunsigned_long_NumChannels)
#define EventWriteOrtcRtpReceiverReportHeaderExtension(xStr_Method, xStr_Kind, xStr_Uri, xUShort_PreferredID, xBool_PreferredEncrypted)

#define EventWriteOrtcRtpReceiverReceive(xStr_Method, xPUID, xPUID_MediaStreamTrackObjectID)
#define EventWriteOrtcRtpReceiverStop(xStr_Method, xPUID)

#define EventWriteOrtcRtpReceiverAddChannel(xStr_Method, xPUID, xPUID_ChannelObjectID)
#define EventWriteOrtcRtpReceiverUpdateChannel(xStr_Method, xPUID, xPUID_ChannelObjectID)
#define EventWriteOrtcRtpReceiverRemoveChannel(xStr_Method, xPUID, xPUID_ChannelObjectID)

#define EventWriteOrtcRtpReceiverAddContributingSource(xStr_Method, xPUID, xDWORD_Csrc, xBYTE_AudioLevel, xbool_VoiceActivityFlag)
#define EventWriteOrtcRtpReceiverUpdateContributingSource(xStr_Method, xPUID, xDWORD_Csrc, xBYTE_AudioLevel, xbool_VoiceActivityFlag)
#define EventWriteOrtcRtpReceiverRemoveContributingSource(xStr_Method, xPUID, xDWORD_Csrc, xBYTE_AudioLevel, xbool_VoiceActivityFlag)

#define EventWriteOrtcRtpReceivedIncomingPacket(xStr_Method, xPUID, xUInt_ViaTransport, xUInt_PacketType, xsize_t_PacketSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcRtpReceiverDeliverIncomingPacketToChannel(xStr_Method, xPUID, xPUID_ChannelObjectID, xUInt_ViaTransport, xUInt_PacketType, xsize_t_PacketSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcRtpReceiverSendOutgoingPacket(xStr_Method, xPUID, xUInt_ViaTransport, xUInt_PacketType, xsize_t_PacketSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcRtpReceiverInternalSecureTransportStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcRtpReceiverInternalWakeEventFired(xStr_Method, xPUID)
#define EventWriteOrtcRtpReceiverInternalTimerEventFired(xStr_Method, xPUID, xPUID_TimerObjectID)
#define EventWriteOrtcRtpReceiverInternalChannelGoneEventFired(xStr_Method, xPUID)

#define EventWriteOrtcRtpReceiverStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcRtpReceiverErrorEventFired(xStr_Method, xPUID, xWORD_Error, xStr_Reason)

#define EventWriteOrtcRtpReceiverRegisterHeaderExtension(xStr_Method, xPUID, xStr_ExtensionURI, xunsigned_short_LocalID, xBool_Encrypted)

#define EventWriteOrtcRtpReceiverSsrcTableEntryAdded(xStr_Method, xPUID, xPUID_ChannelObjectID, xDWORD_Ssrc, xDWORD_RoutingPayload, xlong_long_LastUsageSinceEpochInSeconds, xStr_Rid)
#define EventWriteOrtcRtpReceiverSsrcTableEntryRemoved(xStr_Method, xPUID, xPUID_ChannelObjectID, xDWORD_Ssrc, xDWORD_RoutingPayload, xlong_long_LastUsageSinceEpochInSeconds, xStr_Rid, xStr_Reason)
#define EventWriteOrtcRtpReceiverSsrcTableEntryUpdated(xStr_Method, xPUID, xPUID_ChannelObjectID, xDWORD_Ssrc, xDWORD_RoutingPayload, xlong_long_LastUsageSinceEpochInSeconds, xStr_Rid)

#define EventWriteOrtcRtpReceiverFindMapping(xStr_Method, xPUID, xStr_Rid, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcRtpReceiverFoundMappingByRid(xStr_Method, xPUID, xPUID_ChannelObjectID, xStr_Rid)
#define EventWriteOrtcRtpReceiverFoundMappingBySsrc(xStr_Method, xPUID, xPUID_ChannelObjectID, xDWORD_Ssrc)
#define EventWriteOrtcRtpReceiverFoundMappingByPayloadType(xStr_Method, xPUID, xPUID_ChannelObjectID, xBYTE_PayloadType)

#define EventWriteOrtcRtpReceiverCreateChannel(xStr_Method, xPUID, xPUID_ChannelObjectID)
#define EventWriteOrtcRtpReceiverCloseChannel(xStr_Method, xPUID, xPUID_ChannelObjectID)

#define EventWriteOrtcRtpReceiverUnhandledEventFired(xStr_Method, xPUID, xStr_MuxID, xStr_Rid, xDWORD_Ssrc, xBYTE_PayloadType)

#define EventWriteOrtcRtpReceiverTrackActiveChannelChangedEventFired(xStr_Method, xPUID, xPUID_MediaStreamTrackObjectID, xPUID_ChannelObjectID)

#define EventWriteOrtcRtpSenderCreate(xStr_Method, xPUID, xPUID_MediaStreamTrackObjectID, xPUID_RtpListenerObjectID, xPUID_RtpTransportObjectID, xPUID_RtcpTransportObjectID)
#define EventWriteOrtcRtpSenderDestroy(xStr_Method, xPUID)
#define EventWriteOrtcRtpSenderCancel(xStr_Method, xPUID)

#define EventWriteOrtcRtpSenderSetTransport(xStr_Method, xPUID, xPUID_RtpListenerObjectID, xPUID_RtpTransportObjectID, xPUID_RtcpTransportObjectID)
#define EventWriteOrtcRtpSenderSetTrack(xStr_Method, xPUID, xPUID_MediaStreamTrackObjectID, xStr_Kind)

#define EventWriteOrtcRtpSenderAttachTrackSenderChannel(xStr_Method, xPUID, xPUID_MediaStreamTrackObjectID, xPUID_ChannelObjectID)
#define EventWriteOrtcRtpSenderDetachTrackSenderChannel(xStr_Method, xPUID, xPUID_MediaStreamTrackObjectID, xPUID_ChannelObjectID)

#define EventWriteOrtcRtpSenderSend(xStr_Method, xPUID)
#define EventWriteOrtcRtpSenderStop(xStr_Method, xPUID)

#define EventWriteOrtcRtpSenderStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcRtpSenderErrorEventFired(xStr_Method, xPUID, xWORD_Error, xStr_Reason)

#define EventWriteOrtcRtpSenderAddChannel(xStr_Method, xPUID, xPUID_ChannelObjectID)
#define EventWriteOrtcRtpSenderUpdateChannel(xStr_Method, xPUID, xPUID_ChannelObjectID)
#define EventWriteOrtcRtpSenderRemoveChannel(xStr_Method, xPUID, xPUID_ChannelObjectID)

#define EventWriteOrtcRtpSenderIncomingPacket(xStr_Method, xPUID, xUInt_ViaTransport, xUInt_PacketType, xsize_t_PacketSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcRtpSenderDeliverIncomingPacketToChannel(xStr_Method, xPUID, xPUID_ChannelObjectID, xUInt_ViaTransport, xUInt_PacketType, xsize_t_PacketSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcRtpSenderSendOutgoingPacket(xStr_Method, xPUID, xUInt_ViaTransport, xUInt_PacketType, xsize_t_PacketSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcRtpSenderSsrcConflictEventFired(xStr_Method, xPUID, xPUID_ChannelObjectID, xDWORD_Ssrc, xBool_SelfDestructChannel)

#define EventWriteOrtcRtpSenderInternalChannelErrorEventFired(xStr_Method, xPUID, xPUID_ChannelObjectID, xWORD_Error, xStr_Reason, xBool_SelfDestructChannel)
#define EventWriteOrtcRtpSenderInternalSecureTransportStateChangedEventFired(xStr_Method, xPUID, xPUID_SecureTransportObjectID, xStr_State)
#define EventWriteOrtcRtpSenderInternalWakeEventFired(xStr_Method, xPUID)
#define EventWriteOrtcRtpSenderInternalDestroyChannelEventFired(xStr_Method, xPUID, xPUID_ChannelObjectID)
#define EventWriteOrtcRtpSenderInternalChannelGoneEventFired(xStr_Method, xPUID)

#define EventWriteOrtcRtpReceiverChannelCreate(xStr_Method, xPUID, xPUID_ReceiverObjectID, xPUID_MediaStreamTrackObjectID)
#define EventWriteOrtcRtpReceiverChannelDestroy(xStr_Method, xPUID)

#define EventWriteOrtcRtpReceiverChannelCreateMediaChannel(xStr_Method, xPUID, xPUID_MediaChannelObjectID, xStr_Kind)

#define EventWriteOrtcRtpReceiverChannelDeliverIncomingPacketToMediaChannel(xStr_Method, xPUID, xPUID_MediaChannelObjectID, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcRtpReceiverChannelSendOutgoingPacket(xStr_Method, xPUID, xPUID_ReceiverObjectID, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcRtpReceiverChannelInternalSecureTransportStateChangedEventFired(xStr_Method, xPUID, xStr_State)

#define EventWriteOrtcRtpReceiverChannelInternalUpdateEventFired(xStr_Method, xPUID)

#define EventWriteOrtcRtpSenderChannelCreate(xStr_Method, xPUID, xPUID_RtpSenderObjectID, xPUID_MediaStreamTrackObjectID)
#define EventWriteOrtcRtpSenderChannelDestroy(xStr_Method, xPUID)

#define EventWriteOrtcRtpSenderChannelCreateMediaChannel(xStr_Method, xPUID, xPUID_MediaChannelObjectID, xStr_Kind)
#define EventWriteOrtcRtpSenderChannelChangeTrack(xStr_Method, xPUID, xPUID_MediaChannelObjectID, xPUID_MediaStreamTrackObjectID)

#define EventWriteOrtcRtpSenderChannelDeliverIncomingPacketToMediaChannel(xStr_Method, xPUID, xPUID_MediaChannelObjectID, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcRtpSenderChannelSendOutgoingPacket(xStr_Method, xPUID, xPUID_RtpSenderObjectID, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcRtpSenderChannelInternalSecureTransportStateChangedEventFired(xStr_Method, xPUID, xStr_State)

#define EventWriteOrtcRtpSenderChannelInternalUpdateEventFired(xStr_Method, xPUID)

#define EventWriteOrtcSctpInitCreate(xStr_Method, xPUID)
#define EventWriteOrtcSctpInitDestroy(xStr_Method, xPUID)
#define EventWriteOrtcSctpInitCancel(xStr_Method, xPUID)

#define EventWriteOrtcSctpTransportCreate(xStr_Method, xPUID, xPUID_SctpTransportListenerObjectID, xsize_t_MaxSessionsPerPort, xBool_Incoming, xWORD_LocalPort, xWORD_RemotePort)
#define EventWriteOrtcSctpTransportDestroy(xStr_Method, xPUID)
#define EventWriteOrtcSctpTransportCancel(xStr_Method, xPUID)
#define EventWriteOrtcSctpTransportStep(xStr_Method, xPUID)

#define EventWriteOrtcSctpTransportStart(xStr_Method, xPUID, xsize_t_RemoteMaxMessageSize, xWORD_RemoteMinPOrt, xWORD_RemoteMaxPort, xWORD_MaxUsablePorts, xWORD_MaxSessionsPerPort)
#define EventWriteOrtcSctpTransportStop(xStr_Method, xPUID)

#define EventWriteOrtcSctpTransportRegisterNewDataChannel(xStr_Method, xPUID, xPUID_DataChannelObjectID, xWORD_SessionID)

#define EventWriteOrtcSctpTransportDataChannelEventFired(xStr_Method, xPUID, xPUID_DataChannelObjectID)
#define EventWriteOrtcSctpTransportStateChangedEventFired(xStr_Method, xPUID, xStr_State)
#define EventWriteOrtcSctpTransportErrorEventFired(xStr_Method, xPUID, xWORD_ErrorCode, xStr_Reason)

#define EventWriteOrtcSctpTransportReceivedIncomingPacket(xStr_Method, xPUID, xWORD_SessionID, xWORD_SequenceNumber, xDWORD_Timestamp, xInt_Flags, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcSctpTransportDeliverIncomingPacket(xStr_Method, xPUID, xPUID_DataChannelObjectID, xWORD_SessionID, xWORD_SequenceNumber, xDWORD_Timestamp, xInt_Flags, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcSctpTransportSendOutgoingPacket(xStr_Method, xPUID, xWORD_SessionID, xBool_Ordered, xlong_long_MaxPacketLifeTimeInMilliseconds, xBool_HasMaxRetransmits, xDWORD_MaxRetransmits, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcSctpTransportShutdownDataChannel(xStr_Method, xPUID, xPUID_DataChannelObjectID, xWORD_SessionID)

#define EventWriteOrtcSctpTransportReceivedIncomingDataPacket(xStr_Method, xPUID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcSctpTransportBufferIncomingDataPacket(xStr_Method, xPUID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcSctpTransportDisposeBufferedIncomingDataPacket(xStr_Method, xPUID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcSctpTransportSendOutgoingDataPacket(xStr_Method, xPUID, xPUID_SecureTransportObjectID, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcSctpTransportInternalWakeEventFired(xStr_Method, xPUID)
#define EventWriteOrtcSctpTransportInternalShutdownEventFired(xStr_Method, xPUID)
#define EventWriteOrtcSctpTransportInternalSecureTransportStateChangedEventFired(xStr_Method, xPUID, xPUID_SecureTransportID, xStr_State)

#define EventWriteOrtcSctpTransportListenerCreate(xStr_Method, xPUID, xsize_t_MaxPorts, xWORD_CurrentAllocationPort, xWORD_MinAllocationPort, xWORD_MaxAllocationPort)
#define EventWriteOrtcSctpTransportListenerDestroy(xStr_Method, xPUID)
#define EventWriteOrtcSctpTransportListenerCancel(xStr_Method, xPUID)
#define EventWriteOrtcSctpTransportListenerStep(xStr_Method, xPUID)

#define EventWriteOrtcSctpTransportListenerListen(xStr_Method, xPUID, xsize_t_RemoteMaxMessageSize, xWORD_MinPort, xWORD_MaxPort, xWORD_MaxUseablePorts, xWORD_MaxSessionsPerPort)
#define EventWriteOrtcSctpTransportListenerRegisterNewTransport(xStr_Method, xPUID, xPUID_SecureTransportObjectID, xWORD_LocalPort, xWORD_RemotePort)

#define EventWriteOrtcSctpTransportListenerSctpTransportCreatedEventFired(xStr_Method, xPUID, xPUID_SctpTransportObjectID, xWORD_LocalPort, xWORD_RemotePort)
#define EventWriteOrtcSctpTransportListenerSctpTransportEventFired(xStr_Method, xPUID, xPUID_SctpTransportObjectID, xWORD_LocalPort, xRemotePort)
#define EventWriteOrtcSctpTransportListenerSctpTransportShutdownEventFired(xStr_Method, xPUID, xPUID_SctpTransportObjectID, xWORD_LocalPort, xWORD_RemotePort)

#define EventWriteOrtcSctpTransportListenerReceivedIncomingDataPacket(xStr_Method, xPUID, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcSctpTransportListenerDeliverIncomingDataPacket(xStr_Method, xPUID, xPUID_SctpTransportObjectID, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcSrtpTransportCreate(xStr_Method, xPUID, xPUID_SecureTransportObjectID)
#define EventWriteOrtcSrtpTransportDestroy(xStr_Method, xPUID)

#define EventWriteOrtcSrtpTransportInstallKeyingMaterial(xStr_Method, xPUID, xStr_Direction, xStr_KeyMethod, xStr_KeySalt, xStr_Lifetime, xStr_MkiValue, xWORD_MkiLength)
#define EventWriteOrtcSrtpTransportReceivedIncomingEncryptedPacket(xStr_Method, xPUID, xUInt_ViaComponent, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcSrtpTransportDeliverIncomingDecryptedPacket(xStr_Method, xPUID, xPUID_SecureTransportObjectID, xUInt_ViaComponent, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#define EventWriteOrtcSrtpTransportSendOutgoingPacketAndEncrypt(xStr_Method, xPUID, xUInt_SendOverComponent, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)
#define EventWriteOrtcSrtpTransportSendOutgoingEncryptedPacketViaSecureTransport(xStr_Method, xPUID, xPUID_SecureTransportObjectID, xUInt_SendOverComponent, xUInt_PacketType, xsize_t_BufferSizeInBytes, xPtr_Buffer)

#else

// duplicate testing compilation methods used to verify compilation when macros get defined
namespace ortc
{

inline void EventRegisterOrtcLib() {}
inline void EventUnregisterOrtcLib() {}

inline void EventWriteOrtcCreate(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDestroy(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcCertificateCreate(const char *xStr_Method, PUID xPUID, const char *xStr_KeyGenAlgorithm, const char *xStr_Name, const char *xStr_NamedCurve, size_t xsize_t_KeyLength, size_t xsize_t_RandomBits, const char *xStr_PublicExponenetLength, long long xlong_long_LifetimeInSeconds, long long xlong_long_NotBeforeWindowInSeconds, long long xlong_long_ExpiresInSecondsSinceEpoch) {}
inline void EventWriteOrtcCertificateDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcCertificateGeneratedEventFired(const char *xStr_Method, PUID xPUID, bool xBool_Success) {}
inline void EventWriteOrtcCertificateFingerprint(const char *xStr_Method, PUID xPUID, const char *xStr_FingerprintAlgorithm, const char *xStr_FingerprintValue) {}

inline void EventWriteOrtcDataChannelCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_DataTransport, const char *xStr_Parameters, bool xBool_Incoming, WORD xWORD_SessionID) {}
inline void EventWriteOrtcDataChannelDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelClose(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelStep(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcDataChannelErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_Reason) {}

inline void EventWriteOrtcDataChannelSendControlOpen(const char *xStr_Method, PUID xPUID, BYTE xBYTE_MessageType, BYTE xBYTE_ChannelType, WORD xWORD_Priority, DWORD xDWORD_ReliabilityParameter, WORD xWORD_LabelLength, WORD xWORD_ProtocolLength, const char *xStr_Label, const char *xStr_Protocol) {}
inline void EventWriteOrtcDataChannelSendControlAck(const char *xStr_Method, PUID xPUID, BYTE xBYTE_MessageType) {}

inline void EventWriteOrtcDataChannelBufferedAmountLowThresholdChanged(const char *xStr_Method, PUID xPUID, size_t xsize_t_NewThreshold, size_t xsize_t_OldThreshold, size_t xsize_t_OutgoingBufferFillSize, bool xBool_BufferedAmountLowThresholdFired) {}

inline void EventWriteOrtcDataChannelSendString(const char *xStr_Method, PUID xPUID, const char *xStr_Data) {}
inline void EventWriteOrtcDataChannelSendBinary(const char *xStr_Method, PUID xPUID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcDataChannelOutgoingBufferPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_Type, WORD xWORD_SessionID, bool xBool_Ordered, long long xlong_long_MaxPacketLifetimeInMilliseconds, bool xBool_HasMaxRetransmits, DWORD xDWORD_MaxRetransmits, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcDataChannelOutgoingBufferPacketDelivered(const char *xStr_Method, PUID xPUID, unsigned int xUInt_Type, WORD xWORD_SessionID, bool xBool_Ordered, long long xlong_long_MaxPacketLifetimeInMilliseconds, bool xBool_HasMaxRetransmits, DWORD xDWORD_MaxRetransmits, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcDataChannelReceivedControlOpen(const char *xStr_Method, PUID xPUID, bool xBool_Incoming, BYTE xBYTE_MessageType, BYTE xBYTE_ChannelType, WORD xWORD_Priority, DWORD xDWORD_ReliabilityParameter, WORD xWORD_LabelLength, WORD xWORD_ProtocolLength, const char *xStr_Label, const char *xStr_Protocol) {}
inline void EventWriteOrtcDataChannelReceivedControlAck(const char *xStr_Method, PUID xPUID, BYTE xBYTE_MessageType) {}

inline void EventWriteOrtcDataChannelMessageFiredEvent(const char *xStr_Method, PUID xPUID, unsigned int xUInt_Type, WORD xWORD_SessionID, WORD xWORD_SequenceNumber, DWORD xDWORD_Timestamp, int xInt_Flags, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcDataChannelSCTPTransportDeliverOutgoingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_Type, WORD xWORD_SessionID, bool xBool_Ordered, long long xlong_long_MaxPacketLifetimeInMilliseconds, bool xBool_HasMaxRetransmits, DWORD xDWORD_MaxRetransmits, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcDataChannelSCTPTransportRequestShutdown(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelSCTPTransportRequestNotifyClosed(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelSCTPTransportStateChanged(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelSCTPTransportSendReady(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDataChannelSCTPTransportSendReadyFailure(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_Reason) {}
inline void EventWriteOrtcDataChannelSCTPTransportReceivedIncomingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_Type, WORD xWORD_SessionID, WORD xWORD_SequenceNumber, DWORD xDWORD_Timestamp, int xInt_Flags, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcDtlsTransportCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransport, const char *xStr_Component, size_t xsize_t_MaxPendingDTLSBuffer, size_t xsize_t_MaxPendingRTPPackets, size_t xsize_t_TotalCertificates) {}
inline void EventWriteOrtcDtlsTransportDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDtlsTransportInitialization(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransport, PUID xPUID_RtpListener, size_t xsize_t_TotalCiphers, size_t xsize_t_TotalFingerprints) {}
inline void EventWriteOrtcDtlsTransportStep(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcDtlsTransportCancel(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcDtlsTransportInitializationInstallCipher(const char *xStr_Method, PUID xPUID, const char *xStr_Cipher) {}
inline void EventWriteOrtcDtlsTransportInitializationInstallFingerprint(const char *xStr_Method, PUID xPUID, const char *xStr_Algorithm, const char *xStr_Value, bool xBool_IsLocal) {}

inline void EventWriteOrtcDtlsTransportStart(const char *xStr_Method, PUID xPUID, const char *xStr_Role, size_t xsize_t_TotalFingerprints) {}
inline void EventWriteOrtcDtlsTransportStop(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcDtlsTransportRoleSet(const char *xStr_Method, PUID xPUID, const char *xStr_Role) {}

inline void EventWriteOrtcDtlsTransportReceivedPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaTransport, bool xBool_IsDtlsPacket, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcDtlsTransportReceivedStunPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaTransport) {}

inline void EventWriteOrtcDtlsTransportForwardingEncryptedPacketToSrtpTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_SrtpTransportObjectID, unsigned int xUInt_ViaTransport, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcDtlsTransportForwardingPacketToDataTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_DataTransportObjectID, unsigned int xUInt_ViaTransport, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcDtlsTransportForwardingPacketToRtpListener(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpListenerObjectID, unsigned int xUInt_ViaTransport, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcDtlsTransportSendRtpPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_SendOverComponent, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcDtlsTransportSendDataPacket(const char *xStr_Method, PUID xPUID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcDtlsTransportForwardDataPacketToIceTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcDtlsTransportSendEncryptedRtpPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, unsigned int xUInt_SendOverComponent, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcDtlsTransportInternalTimerEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_TimerObjectID) {}
inline void EventWriteOrtcDtlsTransportInternalIceStateChangeEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, const char *xStr_State) {}
inline void EventWriteOrtcDtlsTransportInternalSrtpTransportLifetimeRemainingEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_SrtpTransportObjectID, ULONG xULONG_LeastLifetimeRemainingPercentageForAllKeys, ULONG xULONG_OverallLifetimeRemainingPercentage) {}

inline void EventWriteOrtcDtlsTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcDtlsTransportErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_Reason) {}

inline void EventWriteOrtcDtlsTransportSrtpKeyingMaterialSetup(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID, const char *xStr_Direction, const char *xStr_Cipher, size_t xsize_t_KeyingMaterialBufferSizeInBytes, const BYTE *xPtr_KeyingMaterialBuffer) {}

inline void EventWriteOrtcIceGathererCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_GethererRouterObjectID, const char *xStr_UsernameFragment, const char *xStr_Password, bool xBool_CreateTCPCandidates, bool xBool_ContinousGathering, size_t xsize_t_TotalInterfacePolicies, size_t xsize_t_TotalIceServers, long long xlong_long_ReflexiveInactivityTimeInSeconds, long long xlong_long_RelayInactivityTimeInSeoncds, long long xlong_long_MaxBufferingTimeInSeconds, long long xlong_long_RecheckIPsInSeconds, size_t xsize_t_MaxTotalBuffers, size_t xsize_t_MaxTCPBufferingSizePendingConnectionInBytes, size_t xsize_t_MaxTCPBufferingSizeConnectedInBytes, bool xBool_GatherPassiveTCP) {}
inline void EventWriteOrtcIceGathererDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererStep(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererCreatedAssociateGatherer(const char *xStr_Method, PUID xPUID, PUID xPUID_AssociatedGathererObjectID) {}

inline void EventWriteOrtcIceGathererInitializeInstallInterfaceNameMapping(const char *xStr_Method, PUID xPUID, const char *xStr_InterfaceNameRegularExpresssion, const char *xStr_InterfaceType, ULONG xULONG_OrderIndex) {}
inline void EventWriteOrtcIceGathererInitializeInstallPreference(const char *xStr_Method, PUID xPUID, const char *xStr_PreferenceType, const char *xStr_Preference, const char *xStr_SubPreference, DWORD xDWORD_PreferenceValue) {}

inline void EventWriteOrtcIceGathererGather(const char *xStr_Method, PUID xPUID, bool xBool_ContinuousGathering, size_t xsize_t_TotalInterfacePolicies, size_t xsize_t_TotalIceServers) {}

inline void EventWriteOrtcIceGathererStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcIceGathererErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_Reason) {}

inline void EventWriteOrtcIceGathererAddCandidateEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_LocalHash, const char *xStr_NotifyHash, const char *xStr_InterfaceType, const char *xStr_Foundation, WORD xWORD_Component, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort) {}
inline void EventWriteOrtcIceGathererRemoveCandidateEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_LocalHash, const char *xStr_NotifyHash, const char *xStr_InterfaceType, const char *xStr_Foundation, WORD xWORD_Component, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort) {}
inline void EventWriteOrtcIceGathererFilterCandidateEventFired(const char *xStr_Method, PUID xPUID, unsigned int xUInt_FilterPolicy, const char *xStr_BoundIP, const char *xStr_InterfaceType, const char *xStr_Foundation, WORD xWORD_Component, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort) {}

inline void EventWriteOrtcIceGathererInstallIceTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, const char *xStr_RemoteUsernameFragment) {}
inline void EventWriteOrtcIceGathererRemoveIceTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID) {}
inline void EventWriteOrtcIceGathererInternalIceTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID) {}

inline void EventWriteOrtcIceGathererRemovetAllIceTransportRelatedRoutes(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID) {}
inline void EventWriteOrtcIceGathererSendIceTransportPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceGathererSendIceTransportPacketFailed(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcIceGathererSendIceTransportPacketViaUdp(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_HostPortObjectID, const char *xStr_RemoteIP, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceGathererSendIceTransportPacketViaTcp(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_TcpPortObjectID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceGathererSendIceTransportPacketViaTurn(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_TurnObjectID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcIceGathererDeliverIceTransportIncomingPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_RouterRouteID, bool xBool_WasBuffered, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceGathererBufferIceTransportIncomingPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_RouterRouteID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcIceGathererDeliverIceTransportIncomingStunPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_RouterRouteID, bool xBool_WasBuffered) {}
inline void EventWriteOrtcIceGathererBufferIceTransportIncomingStunPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_RouterRouteID) {}
inline void EventWriteOrtcIceGathererErrorIceTransportIncomingStunPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, PUID xPUID_RouteID, PUID xPUID_RouterRouteID) {}

inline void EventWriteOrtcIceGathererDisposeBufferedIceTransportIncomingPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_RouterRouteID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceGathererDisposeBufferedIceTransportIncomingStunPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_RouterRouteID) {}

inline void EventWriteOrtcIceGathererTurnSocketReceivedPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_TurnSocketObjectID, const char *xStr_RemoteIP, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceGathererTurnSocketSendPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_TurnSocketObjectID, const char *xStr_RemoteIP, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcIceGathererInstallQuickRoute(const char *xStr_Method, PUID xPUID, const void *xPtr_Candidate, const char *xStr_IPAddress, PUID xPUID_RouteID) {}
inline void EventWriteOrtcIceGathererRemoveQuickRoute(const char *xStr_Method, PUID xPUID, const void *xPtr_Candidate, const char *xStr_IPAddress, PUID xPUID_RouteID) {}
inline void EventWriteOrtcIceGathererSearchQuickRoute(const char *xStr_Method, PUID xPUID, const void *xPtr_Candidate, const char *xStr_IPAddress, bool xBool_Found) {}

inline void EventWriteOrtcIceGathererInternalWakeEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererInternalDnsLoookupCompleteEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_DnsQueryObjectID) {}
inline void EventWriteOrtcIceGathererInternalTimerEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_TimerObjectID, const char *xStr_TimerType, PUID xPUID_RelatedObjectID) {}
inline void EventWriteOrtcIceGathererInternalLikelyReflexiveActivityEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_RouteID, PUID xPUID_RouterRouteID) {}

inline void EventWriteOrtcIceGathererInternalSocketReadReadyEventFired(const char *xStr_Method, PUID xPUID, PUID xRelatedObjectID) {}
inline void EventWriteOrtcIceGathererInternalSocketWriteReadyEventFired(const char *xStr_Method, PUID xPUID, PUID xRelatedObjectID) {}
inline void EventWriteOrtcIceGathererInternalSocketExceptionEventFired(const char *xStr_Method, PUID xPUID, PUID xRelatedObjectID) {}

inline void EventWriteOrtcIceGathererInternalBackOffTimerStateChangedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_BackOffTimerObjectID, const char *xStr_State) {}

inline void EventWriteOrtcIceGathererInternalStunDiscoverySendPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_StunDiscoveryObjectID, const char *xStr_DestinationIP, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceGathererInternalStunDiscoveryCompleteEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_StunDiscoveryObjectID, PUID xPUID_HostPortObjectID, const char *xStr_MappedIP) {}

inline void EventWriteOrtcIceGathererInternalTurnSocketStateChangeEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_TurnSocketObjectID, const char *xStr_State) {}

inline void EventWriteOrtcIceGathererResolveHostIP(const char *xStr_Method, PUID xPUID, PUID xPUID_DnsQueryObjectID, const char *xStr_HostName) {}
inline void EventWriteOrtcIceGathererResolveFoundHostIP(const char *xStr_Method, PUID xPUID, const char *xStr_HostIP, const char *xStr_HostName, const char *xStr_InterfaceName, ULONG xULONG_AdapterSpecific) {}

inline void EventWriteOrtcIceGathererPendingResolveHostIP(const char *xStr_Method, PUID xPUID, const char *xStr_ProfileName, const char *xStr_HostName, const char *xStr_IP) {}

inline void EventWriteOrtcIceGathererHostPortCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_HostPortObjectID, const char *xStr_HostIP) {}
inline void EventWriteOrtcIceGathererHostPortDestroy(const char *xStr_Method, PUID xPUID, PUID xPUID_HostPortObjectID, const char *xStr_HostIP) {}
inline void EventWriteOrtcIceGathererHostPortBind(const char *xStr_Method, PUID xPUID, PUID xPUID_HostPortObjectID, const char *xStr_HostIP, const char *Str_ProtocolType, bool xBool_Success) {}
inline void EventWriteOrtcIceGathererHostPortClose(const char *xStr_Method, PUID xPUID, PUID xPUID_HostPortObjectID, const char *xStr_HostIP, const char *Str_ProtocolType) {}

inline void EventWriteOrtcIceGathererReflexivePortCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_ReflexivePortObjectID, const char *xStr_Server) {}
inline void EventWriteOrtcIceGathererReflexivePortDestroy(const char *xStr_Method, PUID xPUID, PUID xPUID_ReflexivePortObjectID, const char *xStr_Server) {}
inline void EventWriteOrtcIceGathererReflexivePortFoundMapped(const char *xStr_Method, PUID xPUID, PUID xPUID_ReflexivePortObjectID, const char *xStr_MappedIP) {}

inline void EventWriteOrtcIceGathererRelayPortCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_RelayPortObjectID, const char *xStr_Server, const char *xStr_Username, const char *xStr_Credential, const char *xStr_CredentialType) {}
inline void EventWriteOrtcIceGathererRelayPortDestroy(const char *xStr_Method, PUID xPUID, PUID xPUID_RelayPortObjectID, const char *xStr_Server) {}
inline void EventWriteOrtcIceGathererRelayPortFoundIP(const char *xStr_Method, PUID xPUID, PUID xPUID_RelayPortObjectID, const char *xStr_CandidateType, const char *xStr_IP) {}

inline void EventWriteOrtcIceGathererTcpPortCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_TcpPortObjectID, const char *xStr_RemoteIP) {}
inline void EventWriteOrtcIceGathererTcpPortDestroy(const char *xStr_Method, PUID xPUID, PUID xPUID_TcpPortObjectID, const char *xStr_RemoteIP) {}

inline void EventWriteOrtcIceGathererUdpSocketPacketReceivedFrom(const char *xStr_Method, PUID xPUID, const char *xStr_FromIP, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceGathererUdpSocketPacketForwardingToTurnSocket(const char *xStr_Method, PUID xPUID, const char *xStr_FromIP, bool xBool_IsStun, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceGathererUdpSocketPacketSentTo(const char *xStr_Method, PUID xPUID, const char *xStr_BoundIP, const char *xStr_ToIP, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcIceGathererTcpSocketPacketReceivedFrom(const char *xStr_Method, PUID xPUID, const char *xStr_FromIP, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceGathererTcpSocketSentOutgoing(const char *xStr_Method, PUID xPUID, const char *xStr_FromIP, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcIceGathererRouteTrace(const char *xStr_Method, const char *xStr_CallingMethod, const char *xStr_Message, PUID xPUID_IceGathererRouteID, PUID xPUID_IceGathererObjectID, long long xlong_long_LastUsedInMillisecondsSinceEpoch, PUID xPUID_IceTransportObjectID, PUID xPUID_HostPortObjectID, PUID xPUID_RelayPortObjectID, PUID xPUID_TcpPortObjectID, const char *xStr_LocalInterfaceType, const char *xStr_LocalFoundation, DWORD xDWORD_LocalPriority, DWORD xDWORD_LocalUnfreezePriority, const char *xStr_LocalProtocol, const char *xStr_LocalIP, WORD xWORD_LocalPort, const char *xStr_LocalCandidateType, const char *xStr_LocalTcpType, const char *xStr_LocalRelatedAddress, WORD xWORD_LocalRelatedPort) {}

inline void EventWriteOrtcIceGathererRouterCreate(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererRouterDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererRouterCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceGathererRouterInternalEvent(const char *xStr_Method, PUID xPUID, const char *xStr_Event, const char *xStr_CandidateHash, const char *xStr_LocalCandidateIP, WORD xWORD_LocalCandidatePort, const char *xStr_RemoteIP) {}

inline void EventWriteOrtcIceGathererRouterRouteTrace(const char *xStr_Method, const char *xStr_CallingMethod, const char *xStr_Message, PUID xPUID_IceGathererRouterRouteID, const char *xStr_LocalInterfaceType, const char *xStr_LocalFoundation, DWORD xDWORD_LocalPriority, DWORD xDWORD_LocalUnfreezePriority, const char *xStr_LocalProtocol, const char *xStr_LocalIP, WORD xWORD_LocalPort, const char *xStr_LocalCandidateType, const char *xStr_LocalTcpType, const char *xStr_LocalRelatedAddress, WORD xWORD_LocalRelatedPort, const char *xStr_RemoteIP) {}

inline void EventWriteOrtcIceTransportCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_IceGathererObjectID, PUID xPUID_IceGathererRouterObjectID, long long xlong_long_NoPacketReceivedRecheckTimeInSeconds, long long xlong_long_ExpireRouteInSeconds, bool xBool_TestLowerPreferenceCandidatePairs, bool xBool_BlacklistConsent, long long xlong_long_KeepWarmTimeBaseInMilliseconds, long long xlong_long_KeepWarmTimeRandomAddTimeInMilliseconds, size_t xsize_t_MaxBufferedPackets, QWORD xQWORD_ConflictResolver) {}
inline void EventWriteOrtcIceTransportDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportStep(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportCancel(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcIceTransportRouteStateTrackerStateCountChange(const char *xStr_Method, PUID xPUID_IceTransportObjectID, const char *xStr_State, size_t xsize_t_Value) {}

inline void EventWriteOrtcIceTransportStart(const char *xStr_Method, PUID xPUID, PUID xPUID_IceGathererObjectID, bool xBool_RemoteUseCandidateFreezePriority, const char *xStr_RemoteUsernameFragment, const char *xStr_RemotePassword, bool xBool_IceLite, const char *xStr_RemoteParametersHash, const char *xStr_OldRemoteParametersHash, bool xBool_HasRemoteUsernameFragment) {}
inline void EventWriteOrtcIceTransportCreateAssociatedTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_AssociatedTransportObjectID) {}

inline void EventWriteOrtcIceTransportAddRemoteCandidate(const char *xStr_Method, PUID xPUID, const char *xStr_Hash, const char *xStr_InterfaceType, const char *xStr_Foundation, WORD xWORD_Component, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort, bool xBool_PreviouslyAdded) {}
inline void EventWriteOrtcIceTransportAddRemoteCandidateComplete(const char *xStr_Method, PUID xPUID, WORD xWROD_Componenet) {}
inline void EventWriteOrtcIceTransportRemoveRemoteCandidate(const char *xStr_Method, PUID xPUID, const char *xStr_Hash, const char *xStr_InterfaceType, const char *xStr_Foundation, WORD xWORD_Component, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort, bool xBool_WasKnownPreviously) {}
inline void EventWriteOrtcIceTransportRemoveRemoteCandidateComplete(const char *xStr_Method, PUID xPUID, WORD xWORD_Component) {}

inline void EventWriteOrtcIceTransportKeepWarm(const char *xStr_Method, PUID xPUID, const char *xStr_Reason, const char *xStr_CandidatePairHash, bool xBool_KeepWarm) {}

inline void EventWriteOrtcIceTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcIceTransportErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_Reason) {}
inline void EventWriteOrtcIceTransportCandidatePairChangedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_RouteID) {}

inline void EventWriteOrtcIceTransportRouteTrace(const char *xStr_Method, const char *xStr_CallingMethod, const char *xStr_Message, PUID xIceTransportRouteID, PUID xPUID_IceTransportObjectID, const char *xStr_CandidatePairHash, const char *xStr_LocalInterfaceType, const char *xStr_LocalFoundation, DWORD xDWORD_LocalPriority, DWORD xDWORD_LocalUnfreezePriority, const char *xStr_LocalProtocol, const char *xStr_LocalIP, WORD xWORD_LocalPort, const char *xStr_LocalCandidateType, const char *xStr_LocalTcpType, const char *xStr_LocalRelatedAddress, WORD xWORD_LocalRelatedPort, const char *xStr_RemoteInterfaceType, const char *xStr_RemoteFoundation, DWORD xDWORD_RemotePriority, DWORD xDWORD_RemoteUnfreezePriority, const char *xStr_RemoteProtocol, const char *xStr_RemoteIP, WORD xWORD_RemotePort, const char *xStr_RemoteCandidateType, const char *xStr_RemoteTcpType, const char *xStr_RemoteRelatedAddress, WORD xWORD_RemoteRelatedPort, PUID xPUID_IceGathererRouteID, QWORD xQWORD_PendingPriority, long long xlong_long_LastReceivedCheckTimeInMillisecondsSinceEpoch, long long xlong_long_LastSentCheckTimeInMillisecondsSinceEpoch, long long xlong_long_LastReceivedMediaTimeInMillisecondsSinceEpoch, long long xlong_long_LastReceivedResponseTimeInMillisecondsSinceEpoch, bool xBool_Prune, bool xBool_KeepWarm, PUID xPUID_OutgoingCheckStunRequesterObjectID, PUID xPUID_NextKeepWarmTimerObjectID, bool xBool_FrozenPromise, size_t xsize_t_TotalDependentPromises, long long xlong_long_LastRoundTripCheckInMillisecondsSinceEpoch, long long xlong_long_LastRoundTripMeasurementInMilliseconds) {}

inline void EventWriteOrtcIceTransportReceivedPacketFromGatherer(const char *xStr_Method, PUID xPUID, PUID xPUID_RouterRouteID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceTransportReceivedStunPacketFromGatherer(const char *xStr_Method, PUID xPUID, PUID xPUID_RouterRouteID) {}
inline void EventWriteOrtcIceTransportRetryReceivedStunPacketFromGatherer(const char *xStr_Method, PUID xPUID, PUID xPUID_RouterRouteID) {}

inline void EventWriteOrtcIceTransportBufferingIncomingPacket(const char *xStr_Method, PUID xPUID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceTransportDisposingBufferedIncomingPacket(const char *xStr_Method, PUID xPUID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceTransportDeliveringBufferedIncomingPacketToSecureTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcIceTransportDeliveringIncomingPacketToSecureTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceTransportDeliveringIncomingStunPacketToSecureTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID) {}

inline void EventWriteOrtcIceTransportInstallFoundation(const char *xStr_Method, PUID xPUID, const char *xStr_LocalFoundation, const char *xStr_RemoteFoundation, size_t xsize_t_TotalRoutes) {}
inline void EventWriteOrtcIceTransportRemoveFoundation(const char *xStr_Method, PUID xPUID, const char *xStr_LocalFoundation, const char *xStr_RemoteFoundation, size_t xsize_t_TotalRoutes) {}
inline void EventWriteOrtcIceTransportInstallFoundationDependencyFreezePromise(const char *xStr_Method, PUID xPUID, const char *xStr_LocalFoundation, const char *xStr_RemoteFoundation) {}

inline void EventWriteOrtcIceTransportSecureTransportSendPacket(const char *xStr_Method, PUID xPUID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceTransportForwardSecureTransportPacketToGatherer(const char *xStr_Method, PUID xPUID, PUID xPUID_IceGathererObjectID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcIceTransportSendStunPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_IceGathererObjectID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcIceTransportInternalControllerAttachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportControllerObjectID) {}
inline void EventWriteOrtcIceTransportInternalControllerDetachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportControllerObjectID) {}

inline void EventWriteOrtcIceTransportInternalSecureTransportAttachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID) {}
inline void EventWriteOrtcIceTransportInternalSecureTransportDetachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID) {}

inline void EventWriteOrtcIceTransportInternalWarmRoutesChangedEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportInternalDeliveryPendingPacketsEventFired(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcIceTransportInternalWakeEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportInternalTimerEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_TimerObjectID, const char *xStr_TimerType) {}

inline void EventWriteOrtcIceTransportInternalUnfrozenPromiseEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_RouteID) {}

inline void EventWriteOrtcIceTransportInternalGathererStateChangedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceGathererObjectID, const char *xStr_State) {}
inline void EventWriteOrtcIceTransportInternalGathererAddLocalCandidateEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceGathererObjectID, const char *xStr_InterfaceType, const char *xStr_Foundation, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort) {}
inline void EventWriteOrtcIceTransportInternalGathererAddLocalCandidateCompleteEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceGathererObjectID, WORD xWORD_Componeent) {}
inline void EventWriteOrtcIceTransportInternalGathererRemoveLocalCandidateEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceGathererObjectID, const char *xStr_InterfaceType, const char *xStr_Foundation, DWORD xDWORD_Priority, DWORD xDWORD_UnfreezePriority, const char *xStr_Protocol, const char *xStr_IP, WORD xWORD_Port, const char *xStr_CandidateType, const char *xStr_TcpType, const char *xStr_RelatedAddress, WORD xWORD_RelatedPort) {}

inline void EventWriteOrtcIceTransportInternalStunRequesterCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_StunRequesterObjectID) {}
inline void EventWriteOrtcIceTransportInternalStunRequesterSendPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_StunRequesterObjectID, const char *xStr_DestinationIP, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcIceTransportInternalStunRequesterReceivedResponse(const char *xStr_Method, PUID xPUID, PUID xPUID_StunRequesterObjectID, const char *xStr_FromIP) {}
inline void EventWriteOrtcIceTransportInternalStunRequesterReceivedResponseMismatch(const char *xStr_Method, PUID xPUID, PUID xPUID_StunRequesterObjectID, const char *xStr_FromIP, const char *xStr_ExpectingIP) {}
inline void EventWriteOrtcIceTransportInternalStunRequesterTimedOut(const char *xStr_Method, PUID xPUID, PUID xPUID_StunRequesterObjectID) {}

inline void EventWriteOrtcIceTransportInternalRoleConflictDetectedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_NewRole, const char *xStr_Reason) {}

inline void EventWriteOrtcIceTransportControllerCreate(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportControllerDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportControllerCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportControllerStep(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcIceTransportControllerInternalWakeEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcIceTransportControllerInternalTransportAttachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, size_t xsize_t_AttachedOrderID, bool xBool_HasInsertIndex, size_t xsize_t_InsertIndex) {}
inline void EventWriteOrtcIceTransportControllerInternalTransportDetachedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, size_t xsize_t_DetachedOrderID) {}

inline void EventWriteOrtcIceTransportControllerWaitUntilUnfrozen(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, const char *xStr_LocalFoundation, const char *xStr_RemoteFoundation) {}
inline void EventWriteOrtcIceTransportControllerNoNeedToWaitUntilUnfrozen(const char *xStr_Method, PUID xPUID, PUID xPUID_IceTransportObjectID, const char *xStr_LocalFoundation, const char *xStr_RemoteFoundation) {}

inline void EventWriteOrtcRtpListenerCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpTransport, size_t xsize_t_MaxBufferedRtpPackets, long long xlong_long_MaxRtpPacketAgeInSeconds, size_t xsize_t_MaxBufferedRtcpPackets, long long xlong_long_AmbigousPayloadMappingMinDifferenceInMilliseconds, long long xlong_long_SsrcTableExpiresInSeconds, long long xlong_long_UnhandledEventsExpiresInSeconds) {}
inline void EventWriteOrtcRtpListenerDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpListenerCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpListenerStep(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpListenerFindMapping(const char *xStr_Method, PUID xPUID, const char *xStr_MuxID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcRtpListenerFoundMappingByMuxID(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, const char *xStr_MuxID) {}
inline void EventWriteOrtcRtpListenerFoundMappingBySsrc(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, DWORD xDWORD_Ssrc) {}
inline void EventWriteOrtcRtpListenerFoundMappingByPayloadType(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, BYTE xBYTE_PayloadType) {}

inline void EventWriteOrtcRtpListenerStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcRtpListenerErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_ErrorCode, const char *xStr_Reason) {}
inline void EventWriteOrtcRtpListenerUnhandledEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_MuxID, const char *xStr_Rid, DWORD xDWORD_Ssrc, BYTE xBYTE_PayloadType) {}

inline void EventWriteOrtcRtpListenerRegisterHeaderExtension(const char *xStr_Method, PUID xPUID, PUID xPUID_RegisterForObject, const char *xStr_ExtensionURI, unsigned short xunsigned_short_LocalID, bool xBool_Encrypted, size_t xsize_t_TotalReferences) {}
inline void EventWriteOrtcRtpListenerUnregisterHeaderExtension(const char *xStr_Method, PUID xPUID, PUID xPUID_RegisterForObject, const char *xStr_ExtensionURI, unsigned short xunsigned_short_LocalID, bool xBool_Encrypted, size_t xsize_t_TotalReferences) {}

inline void EventWriteOrtcRtpListenerReceivedIncomingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaComponent, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcRtpListenerBufferIncomingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaComponent, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcRtpListenerForwardIncomingPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_SenderOrReceiverObjectID, unsigned int xUInt_ViaComponent, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcRtpListenerDisposeBufferedIncomingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcRtpListenerRegisterReceiver(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, PUID xPUID_OrderID, const char *xStr_Kind) {}
inline void EventWriteOrtcRtpListenerUnregisterReceiver(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID) {}

inline void EventWriteOrtcRtpListenerRegisterSender(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpSenderObjectID) {}
inline void EventWriteOrtcRtpListenerUnregisterSender(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpSenderObjectID) {}

inline void EventWriteOrtcRtpListenerInternalWakeEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpListenerInternalTimerEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_TimerObjectID, const char *xStr_TimerType) {}

inline void EventWriteOrtcRtpListenerSsrcTableEntryAdded(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, DWORD xDWORD_Ssrc, long long xlong_long_LastUsageSinceEpochInSeconds, const char *xStr_MuxID) {}
inline void EventWriteOrtcRtpListenerSsrcTableEntryRemoved(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, DWORD xDWORD_Ssrc, long long xlong_long_LastUsageSinceEpochInSeconds, const char *xStr_MuxID, const char *xStr_Reason) {}
inline void EventWriteOrtcRtpListenerSsrcTableEntryUpdated(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpReceiverObjectID, DWORD xDWORD_Ssrc, long long xlong_long_LastUsageSinceEpochInSeconds, const char *xStr_MuxID) {}

inline void EventWriteOrtcRtpMediaEngineCreate(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpMediaEngineDestroy(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcRtpReceiverCreate(const char *xStr_Method, PUID xPUID, const char *xStr_Kind, PUID xPUID_RtpListenerObjectID, PUID xPUID_RtpTransportObjectID, PUID xPUID_RtcpTransportObjectID, PUID xPUID_MediaStreamTrackObjectID, size_t xsize_t_MaxBufferedRtpPackets, long long xlong_long_MaxRTPPacketAgeInSeconds, long long xlong_long_LockAfterSwitchTimeInMilliseconds, long long xlong_long_AmbigousPayloadMappingMinDifferenceInMilliseconds, long long xlong_long_SSRCTableExpiresInSeconds, long long xlong_long_ContributingSourcesExpiry) {}
inline void EventWriteOrtcRtpReceiverDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpReceiverStep(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpReceiverCancel(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcRtpReceiverSetTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpListenerObjectID, PUID xPUID_RtpTransportObjectID, PUID xPUID_RtcpTransportObjectID) {}

inline void EventWriteOrtcRtpReceiverReportRtcpFeedback(const char *xStr_Method, const char *xStr_Type, const char *xStr_Parameter) {}
inline void EventWriteOrtcRtpReceiverReportCodec(const char *xStr_Method, const char *xStr_Name, const char *xStr_Kind, unsigned long xunsigned_long_CodecRate, BYTE xBYTE_PreferredPayloadType, unsigned long xunsigned_long_PTime, unsigned long xunsigned_long_MaxPTime, unsigned long xunsigned_long_NumChannels) {}
inline void EventWriteOrtcRtpReceiverReportHeaderExtension(const char *xStr_Method, const char *xStr_Kind, const char *xStr_Uri, unsigned short xUShort_PreferredID, bool xBool_PreferredEncrypted) {}

inline void EventWriteOrtcRtpReceiverReceive(const char *xStr_Method, PUID xPUID, PUID xPUID_MediaStreamTrackObjectID) {}
inline void EventWriteOrtcRtpReceiverStop(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcRtpReceiverAddChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID) {}
inline void EventWriteOrtcRtpReceiverUpdateChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID) {}
inline void EventWriteOrtcRtpReceiverRemoveChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID) {}

inline void EventWriteOrtcRtpReceiverAddContributingSource(const char *xStr_Method, PUID xPUID, DWORD xDWORD_Csrc, BYTE xBYTE_AudioLevel, bool xbool_VoiceActivityFlag) {}
inline void EventWriteOrtcRtpReceiverUpdateContributingSource(const char *xStr_Method, PUID xPUID, DWORD xDWORD_Csrc, BYTE xBYTE_AudioLevel, bool xbool_VoiceActivityFlag) {}
inline void EventWriteOrtcRtpReceiverRemoveContributingSource(const char *xStr_Method, PUID xPUID, DWORD xDWORD_Csrc, BYTE xBYTE_AudioLevel, bool xbool_VoiceActivityFlag) {}

inline void EventWriteOrtcRtpReceivedIncomingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaTransport, unsigned int xUInt_PacketType, size_t xsize_t_PacketSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcRtpReceiverDeliverIncomingPacketToChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID, unsigned int xUInt_ViaTransport, unsigned int xUInt_PacketType, size_t xsize_t_PacketSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcRtpReceiverSendOutgoingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaTransport, unsigned int xUInt_PacketType, size_t xsize_t_PacketSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcRtpReceiverInternalSecureTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcRtpReceiverInternalWakeEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpReceiverInternalTimerEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_TimerObjectID) {}
inline void EventWriteOrtcRtpReceiverInternalChannelGoneEventFired(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcRtpReceiverStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcRtpReceiverErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_Reason) {}

inline void EventWriteOrtcRtpReceiverRegisterHeaderExtension(const char *xStr_Method, PUID xPUID, const char *xStr_ExtensionURI, unsigned short xunsigned_short_LocalID, bool xBool_Encrypted) {}

inline void EventWriteOrtcRtpReceiverSsrcTableEntryAdded(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID, DWORD xDWORD_Ssrc, DWORD xDWORD_RoutingPayload, long long xlong_long_LastUsageSinceEpochInSeconds, const char *xStr_Rid) {}
inline void EventWriteOrtcRtpReceiverSsrcTableEntryRemoved(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID, DWORD xDWORD_Ssrc, DWORD xDWORD_RoutingPayload, long long xlong_long_LastUsageSinceEpochInSeconds, const char *xStr_Rid, const char *xStr_Reason) {}
inline void EventWriteOrtcRtpReceiverSsrcTableEntryUpdated(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID, DWORD xDWORD_Ssrc, DWORD xDWORD_RoutingPayload, long long xlong_long_LastUsageSinceEpochInSeconds, const char *xStr_Rid) {}

inline void EventWriteOrtcRtpReceiverFindMapping(const char *xStr_Method, PUID xPUID, const char *xStr_Rid, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcRtpReceiverFoundMappingByRid(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID, const char *xStr_Rid) {}
inline void EventWriteOrtcRtpReceiverFoundMappingBySsrc(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID, DWORD xDWORD_Ssrc) {}
inline void EventWriteOrtcRtpReceiverFoundMappingByPayloadType(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID, BYTE xBYTE_PayloadType) {}

inline void EventWriteOrtcRtpReceiverCreateChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID) {}
inline void EventWriteOrtcRtpReceiverCloseChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID) {}

inline void EventWriteOrtcRtpReceiverUnhandledEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_MuxID, const char *xStr_Rid, DWORD xDWORD_Ssrc, BYTE xBYTE_PayloadType) {}

inline void EventWriteOrtcRtpReceiverTrackActiveChannelChangedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_MediaStreamTrackObjectID, PUID xPUID_ChannelObjectID) {}

inline void EventWriteOrtcRtpSenderCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_MediaStreamTrackObjectID, PUID xPUID_RtpListenerObjectID, PUID xPUID_RtpTransportObjectID, PUID xPUID_RtcpTransportObjectID) {}
inline void EventWriteOrtcRtpSenderDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpSenderCancel(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcRtpSenderSetTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpListenerObjectID, PUID xPUID_RtpTransportObjectID, PUID xPUID_RtcpTransportObjectID) {}
inline void EventWriteOrtcRtpSenderSetTrack(const char *xStr_Method, PUID xPUID, PUID xPUID_MediaStreamTrackObjectID, const char *xStr_Kind) {}

inline void EventWriteOrtcRtpSenderAttachTrackSenderChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_MediaStreamTrackObjectID, PUID xPUID_ChannelObjectID) {}
inline void EventWriteOrtcRtpSenderDetachTrackSenderChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_MediaStreamTrackObjectID, PUID xPUID_ChannelObjectID) {}

inline void EventWriteOrtcRtpSenderSend(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpSenderStop(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcRtpSenderStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcRtpSenderErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_Error, const char *xStr_Reason) {}

inline void EventWriteOrtcRtpSenderAddChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID) {}
inline void EventWriteOrtcRtpSenderUpdateChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID) {}
inline void EventWriteOrtcRtpSenderRemoveChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID) {}

inline void EventWriteOrtcRtpSenderIncomingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaTransport, unsigned int xUInt_PacketType, size_t xsize_t_PacketSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcRtpSenderDeliverIncomingPacketToChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID, unsigned int xUInt_ViaTransport, unsigned int xUInt_PacketType, size_t xsize_t_PacketSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcRtpSenderSendOutgoingPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaTransport, unsigned int xUInt_PacketType, size_t xsize_t_PacketSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcRtpSenderSsrcConflictEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID, DWORD xDWORD_Ssrc, bool xBool_SelfDestructChannel) {}

inline void EventWriteOrtcRtpSenderInternalChannelErrorEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID, WORD xWORD_Error, const char *xStr_Reason, bool xBool_SelfDestructChannel) {}
inline void EventWriteOrtcRtpSenderInternalSecureTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID, const char *xStr_State) {}
inline void EventWriteOrtcRtpSenderInternalWakeEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcRtpSenderInternalDestroyChannelEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_ChannelObjectID) {}
inline void EventWriteOrtcRtpSenderInternalChannelGoneEventFired(const char *xStr_Method, PUID xPUID) {}


inline void EventWriteOrtcRtpReceiverChannelCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_ReceiverObjectID, PUID xPUID_MediaStreamTrackObjectID) {}
inline void EventWriteOrtcRtpReceiverChannelDestroy(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcRtpReceiverChannelCreateMediaChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_MediaChannelObjectID, const char *xStr_Kind) {}

inline void EventWriteOrtcRtpReceiverChannelDeliverIncomingPacketToMediaChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_MediaChannelObjectID, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcRtpReceiverChannelSendOutgoingPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_ReceiverObjectID, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcRtpReceiverChannelInternalSecureTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}

inline void EventWriteOrtcRtpReceiverChannelInternalUpdateEventFired(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcRtpSenderChannelCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpSenderObjectID, PUID xPUID_MediaStreamTrackObjectID) {}
inline void EventWriteOrtcRtpSenderChannelDestroy(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcRtpSenderChannelCreateMediaChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_MediaChannelObjectID, const char *xStr_Kind) {}
inline void EventWriteOrtcRtpSenderChannelChangeTrack(const char *xStr_Method, PUID xPUID, PUID xPUID_MediaChannelObjectID, PUID xPUID_MediaStreamTrackObjectID) {}

inline void EventWriteOrtcRtpSenderChannelDeliverIncomingPacketToMediaChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_MediaChannelObjectID, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcRtpSenderChannelSendOutgoingPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_RtpSenderObjectID, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcRtpSenderChannelInternalSecureTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}

inline void EventWriteOrtcRtpSenderChannelInternalUpdateEventFired(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcSctpInitCreate(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcSctpInitDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcSctpInitCancel(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcSctpTransportCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_SctpTransportListenerObjectID, size_t xsize_t_MaxSessionsPerPort, bool xBool_Incoming, WORD xWORD_LocalPort, WORD xWORD_RemotePort) {}
inline void EventWriteOrtcSctpTransportDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcSctpTransportCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcSctpTransportStep(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcSctpTransportStart(const char *xStr_Method, PUID xPUID, size_t xsize_t_RemoteMaxMessageSize, WORD xWORD_RemoteMinPOrt, WORD xWORD_RemoteMaxPort, WORD xWORD_MaxUsablePorts, WORD xWORD_MaxSessionsPerPort) {}
inline void EventWriteOrtcSctpTransportStop(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcSctpTransportRegisterNewDataChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_DataChannelObjectID, WORD xWORD_SessionID) {}

inline void EventWriteOrtcSctpTransportDataChannelEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_DataChannelObjectID) {}
inline void EventWriteOrtcSctpTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, const char *xStr_State) {}
inline void EventWriteOrtcSctpTransportErrorEventFired(const char *xStr_Method, PUID xPUID, WORD xWORD_ErrorCode, const char *xStr_Reason) {}

inline void EventWriteOrtcSctpTransportReceivedIncomingPacket(const char *xStr_Method, PUID xPUID, WORD xWORD_SessionID, WORD xWORD_SequenceNumber, DWORD xDWORD_Timestamp, int xInt_Flags, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcSctpTransportDeliverIncomingPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_DataChannelObjectID, WORD xWORD_SessionID, WORD xWORD_SequenceNumber, DWORD xDWORD_Timestamp, int xInt_Flags, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcSctpTransportSendOutgoingPacket(const char *xStr_Method, PUID xPUID, WORD xWORD_SessionID, bool xBool_Ordered, long long xlong_long_MaxPacketLifeTimeInMilliseconds, bool xBool_HasMaxRetransmits, DWORD xDWORD_MaxRetransmits, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcSctpTransportShutdownDataChannel(const char *xStr_Method, PUID xPUID, PUID xPUID_DataChannelObjectID, WORD xWORD_SessionID) {}

inline void EventWriteOrtcSctpTransportReceivedIncomingDataPacket(const char *xStr_Method, PUID xPUID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcSctpTransportBufferIncomingDataPacket(const char *xStr_Method, PUID xPUID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcSctpTransportDisposeBufferedIncomingDataPacket(const char *xStr_Method, PUID xPUID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcSctpTransportSendOutgoingDataPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcSctpTransportInternalWakeEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcSctpTransportInternalShutdownEventFired(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcSctpTransportInternalSecureTransportStateChangedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportID, const char *xStr_State) {}

inline void EventWriteOrtcSctpTransportListenerCreate(const char *xStr_Method, PUID xPUID, size_t xsize_t_MaxPorts, WORD xWORD_CurrentAllocationPort, WORD xWORD_MinAllocationPort, WORD xWORD_MaxAllocationPort) {}
inline void EventWriteOrtcSctpTransportListenerDestroy(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcSctpTransportListenerCancel(const char *xStr_Method, PUID xPUID) {}
inline void EventWriteOrtcSctpTransportListenerStep(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcSctpTransportListenerListen(const char *xStr_Method, PUID xPUID, size_t xsize_t_RemoteMaxMessageSize, WORD xWORD_MinPort, WORD xWORD_MaxPort, WORD xWORD_MaxUseablePorts, WORD xWORD_MaxSessionsPerPort) {}
inline void EventWriteOrtcSctpTransportListenerRegisterNewTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID, WORD xWORD_LocalPort, WORD xWORD_RemotePort) {}

inline void EventWriteOrtcSctpTransportListenerSctpTransportCreatedEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_SctpTransportObjectID, WORD xWORD_LocalPort, WORD xWORD_RemotePort) {}
inline void EventWriteOrtcSctpTransportListenerSctpTransportEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_SctpTransportObjectID, WORD xWORD_LocalPort, WORD xWORD_RemotePort) {}
inline void EventWriteOrtcSctpTransportListenerSctpTransportShutdownEventFired(const char *xStr_Method, PUID xPUID, PUID xPUID_SctpTransportObjectID, WORD xWORD_LocalPort, WORD xWORD_RemotePort) {}

inline void EventWriteOrtcSctpTransportListenerReceivedIncomingDataPacket(const char *xStr_Method, PUID xPUID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcSctpTransportListenerDeliverIncomingDataPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_SctpTransportObjectID, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcSrtpTransportCreate(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID) {}
inline void EventWriteOrtcSrtpTransportDestroy(const char *xStr_Method, PUID xPUID) {}

inline void EventWriteOrtcSrtpTransportInstallKeyingMaterial(const char *xStr_Method, PUID xPUID, const char *xStr_Direction, const char *xStr_KeyMethod, const char *xStr_KeySalt, const char *xStr_Lifetime, const char *xStr_MkiValue, WORD xWORD_MkiLength) {}
inline void EventWriteOrtcSrtpTransportReceivedIncomingEncryptedPacket(const char *xStr_Method, PUID xPUID, unsigned int xUInt_ViaComponent, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcSrtpTransportDeliverIncomingDecryptedPacket(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID, unsigned int xUInt_ViaComponent, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

inline void EventWriteOrtcSrtpTransportSendOutgoingPacketAndEncrypt(const char *xStr_Method, PUID xPUID, unsigned int xUInt_SendOverComponent, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}
inline void EventWriteOrtcSrtpTransportSendOutgoingEncryptedPacketViaSecureTransport(const char *xStr_Method, PUID xPUID, PUID xPUID_SecureTransportObjectID, unsigned int xUInt_SendOverComponent, unsigned int xUInt_PacketType, size_t xsize_t_BufferSizeInBytes, const BYTE *xPtr_Buffer) {}

}
#endif //ndef ORTC_USE_NOOP_EVENT_TRACE_MACROS

#endif //USE_ETW
