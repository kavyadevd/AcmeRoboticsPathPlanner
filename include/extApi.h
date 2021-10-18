/**
 * @file extApi.h
 * @copyright All rights reserved
 *
 */
#ifndef _EXTAPI__  // NOLINT
#define _EXTAPI__

#ifdef __cplusplus
extern "C" {
#endif
#ifdef NON_MATLAB_PARSING /* when compiling, make sure NON_MATLAB_PARSING is always defined! */
    #include "extApiPlatform.h"
    #include "simConst.h"
#else
    typedef char simxChar;
    typedef unsigned char simxUChar;
    typedef short simxShort;  // NOLINT
    typedef unsigned short simxUShort;  // NOLINT
    typedef int simxInt;
    typedef unsigned int simxUInt;
    typedef float simxFloat;
    typedef void simxVoid;
    typedef double simxDouble;
#endif /* else NON_MATLAB_PARSING */

#ifdef _WIN32
    #define EXTAPI_DLLEXPORT extern __declspec(dllexport)
#endif
#if defined (__linux) || defined (__APPLE__)
    #define EXTAPI_DLLEXPORT extern
#endif

/* Use following to test endianness detection on little endian machines (endianness of the client is handled on the server side)
#define ENDIAN_TEST
*/

#ifdef NON_MATLAB_PARSING

/* Various other functions, not to be called directly */
simxVoid _waitUntilMessageArrived(simxInt clientID,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _setLastFetchedCmd(simxInt clientID,simxUChar* cmdPtr,simxInt* error);   // NOLINT  // NOLINT

simxUChar* _exec_null(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _exec_null_buffer(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,simxUChar* buffer,simxInt bufferSize,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _exec_int(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,simxInt intValue,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _exec_intint(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,simxInt intValue1,simxInt intValue2,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _exec_string(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,const simxUChar* stringValue,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _exec_int_int(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,simxInt intValue,simxInt intValue2,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _exec_intint_int(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,simxInt intValue1,simxInt intValue2,simxInt intValue3,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _exec_intint_buffer(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,simxInt intValue1,simxInt intValue2,simxUChar* buffer,simxInt bufferSize,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _exec_int_float(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,simxInt intValue,simxFloat floatValue,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _exec_int_buffer(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,simxInt intValue,simxUChar* buffer,simxInt bufferSize,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _exec_string_buffer(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,const simxUChar* stringValue,simxUChar* buffer,simxInt bufferSize,simxInt* error);   // NOLINT  // NOLINT
simxUChar* _exec_intstringstring_buffer(simxInt clientID,simxInt cmdRaw,simxInt opMode,simxUChar options,simxInt intValue,const simxUChar* stringValue1,const simxUChar* stringValue2,simxUChar* buffer,simxInt bufferSize,simxInt* error);   // NOLINT  // NOLINT

simxUChar _readPureDataChar(simxUChar* commandPointer,simxInt stringCnt,simxInt byteOffset);   // NOLINT  // NOLINT
simxInt _readPureDataInt(simxUChar* commandPointer,simxInt stringCnt,simxInt byteOffset);   // NOLINT  // NOLINT
simxFloat _readPureDataFloat(simxUChar* commandPointer,simxInt stringCnt,simxInt byteOffset);   // NOLINT  // NOLINT
simxInt _getCmdDataSize(simxUChar* commandPointer);   // NOLINT

simxUChar* _getCommandPointer_(simxInt cmdRaw,const simxUChar* commandBufferStart,simxInt commandBufferSize);   // NOLINT  // NOLINT
simxUChar* _getCommandPointer_i(simxInt cmdRaw,simxInt intValue,const simxUChar* commandBufferStart,simxInt commandBufferSize);   // NOLINT  // NOLINT
simxUChar* _getCommandPointer_ii(simxInt cmdRaw,simxInt intValue1,simxInt intValue2,const simxUChar* commandBufferStart,simxInt commandBufferSize);   // NOLINT  // NOLINT
simxUChar* _getCommandPointer_s(simxInt cmdRaw,const simxUChar* stringValue,const simxUChar* commandBufferStart,simxInt commandBufferSize);   // NOLINT  // NOLINT
simxUChar* _getCommandPointer_iss(simxInt cmdRaw,simxInt intValue,const simxUChar* stringValue1,const simxUChar* stringValue2,const simxUChar* commandBufferStart,simxInt commandBufferSize);   // NOLINT  // NOLINT

simxUChar* _appendCommand_(simxInt cmd,simxUChar options,simxUShort delayOrSplit,simxUChar* buffer,simxInt* buffer_bufferSize,simxInt* buffer_dataSize);   // NOLINT  // NOLINT
simxUChar* _appendCommand_null_buff(simxInt cmd,simxUChar options,simxUChar* buffer,simxInt bufferSize,simxUShort delayOrSplit,simxUChar* destBuffer,simxInt* destBuffer_bufferSize,simxInt* destBuffer_dataSize);   // NOLINT  // NOLINT
simxUChar* _appendCommand_i(simxInt cmd,simxUChar options,simxInt intValue,simxUShort delayOrSplit,simxUChar* buffer,simxInt* buffer_bufferSize,simxInt* buffer_dataSize);   // NOLINT
simxUChar* _appendCommand_ii(simxInt cmd,simxUChar options,simxInt intValue1,simxInt intValue2,simxUShort delayOrSplit,simxUChar* buffer,simxInt* buffer_bufferSize,simxInt* buffer_dataSize);   // NOLINT
simxUChar* _appendCommand_s(simxInt cmd,simxUChar options,const simxUChar* stringValue,simxUShort delayOrSplit,simxUChar* buffer,simxInt* buffer_bufferSize,simxInt* buffer_dataSize);   // NOLINT
simxUChar* _appendCommand_i_i(simxInt cmd,simxUChar options,simxInt intValue,simxInt intValue2,simxUShort delayOrSplit,simxUChar* buffer,simxInt* buffer_bufferSize,simxInt* buffer_dataSize);   // NOLINT
simxUChar* _appendCommand_ii_i(simxInt cmd,simxUChar options,simxInt intValue1,simxInt intValue2,simxInt intValue3,simxUShort delayOrSplit,simxUChar* buffer,simxInt* buffer_bufferSize,simxInt* buffer_dataSize);   // NOLINT
simxUChar* _appendCommand_i_f(simxInt cmd,simxUChar options,simxInt intValue,simxFloat floatValue,simxUShort delayOrSplit,simxUChar* buffer,simxInt* buffer_bufferSize,simxInt* buffer_dataSize);   // NOLINT
simxUChar* _appendCommand_i_buff(simxInt cmd,simxUChar options,simxInt intValue,simxUChar* buffer,simxInt bufferSize,simxUShort delayOrSplit,simxUChar* destBuffer,simxInt* destBuffer_bufferSize,simxInt* destBuffer_dataSize);   // NOLINT
simxUChar* _appendCommand_ii_buff(simxInt cmd,simxUChar options,simxInt intValue1,simxInt intValue2,simxUChar* buffer,simxInt bufferSize,simxUShort delayOrSplit,simxUChar* destBuffer,simxInt* destBuffer_bufferSize,simxInt* destBuffer_dataSize);   // NOLINT
simxUChar* _appendCommand_s_buff(simxInt cmd,simxUChar options,const simxUChar* stringValue,simxUChar* buffer,simxInt bufferSize,simxUShort delayOrSplit,simxUChar* destBuffer,simxInt* destBuffer_bufferSize,simxInt* destBuffer_dataSize);   // NOLINT
simxUChar* _appendCommand_iss_buff(simxInt cmd,simxUChar options,simxInt intValue,const simxUChar* stringValue1,const simxUChar* stringValue2,simxUChar* buffer,simxInt bufferSize,simxUShort delayOrSplit,simxUChar* destBuffer,simxInt* destBuffer_bufferSize,simxInt* destBuffer_dataSize);   // NOLINT

simxUChar* _appendChunkToBuffer(const simxUChar* chunk,simxInt chunkSize,simxUChar* buffer,simxInt* buffer_bufferSize,simxInt* buffer_dataSize);   // NOLINT
simxVoid _removeChunkFromBuffer(const simxUChar* bufferStart,simxUChar* chunkStart,simxInt chunkSize,simxInt* buffer_dataSize);   // NOLINT

simxUChar* _appendCommandToBufferAndTakeIntoAccountPreviouslyReceivedData(const simxUChar* cmdPtr,simxUChar* cmdBuffer,simxInt cmdBufferSize,const simxUChar* chunk,simxInt chunkSize,simxUChar* buffer,simxInt* buffer_bufferSize,simxInt* buffer_dataSize);   // NOLINT

simxInt _removeCommandReply_null(simxInt clientID,simxInt cmdRaw);   // NOLINT
simxInt _removeCommandReply_int(simxInt clientID,simxInt cmdRaw,simxInt intValue);   // NOLINT
simxInt _removeCommandReply_intint(simxInt clientID,simxInt cmdRaw,simxInt intValue1,simxInt intValue2);   // NOLINT
simxInt _removeCommandReply_string(simxInt clientID,simxInt cmdRaw,const simxUChar* stringValue);   // NOLINT
simxInt _removeCommandReply_intstringstring(simxInt clientID,simxInt cmdRaw,simxInt intValue,const simxUChar* stringValue1,const simxUChar* stringValue2);   // NOLINT

simxUChar* _getSameCommandPointer(const simxUChar* cmdPtr,simxUChar* cmdBuffer,simxInt cmdBufferSize);   // NOLINT
SIMX_THREAD_RET_TYPE _communicationThread(simxVoid* p);   // NOLINT

simxUShort _getCRC(const simxUChar* data,simxInt length);   // NOLINT

simxUChar _sendMessage_socketOrSharedMem(simxInt clientID,const simxUChar* message,simxInt messageSize,simxUChar usingSharedMem);   // NOLINT
simxUChar* _receiveReplyMessage_socketOrSharedMem(simxInt clientID,simxInt* messageSize,simxUChar usingSharedMem);   // NOLINT
simxUChar _sendSimplePacket_socket(simxInt clientID,const simxUChar* packet,simxShort packetLength,simxShort packetsLeft);   // NOLINT
simxInt _receiveSimplePacket_socket(simxInt clientID,simxUChar** packet,simxShort* packetSize);   // NOLINT

#endif /* NON_MATLAB_PARSING */


/* The remote API functions */
/* EXTAPI_DLLEXPORT simxFloat mtlb_simxTest(simxFloat* b);   // NOLINT */
EXTAPI_DLLEXPORT simxInt simxGetJointPosition(simxInt clientID,simxInt jointHandle,simxFloat* position,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetJointPosition(simxInt clientID,simxInt jointHandle,simxFloat position,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetJointMatrix(simxInt clientID,simxInt jointHandle,simxFloat* matrix,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetSphericalJointMatrix(simxInt clientID,simxInt jointHandle,simxFloat* matrix,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetJointTargetVelocity(simxInt clientID,simxInt jointHandle,simxFloat targetVelocity,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetJointTargetPosition(simxInt clientID,simxInt jointHandle,simxFloat targetPosition,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxJointGetForce(simxInt clientID,simxInt jointHandle,simxFloat* force,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetJointForce(simxInt clientID,simxInt jointHandle,simxFloat* force,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetJointForce(simxInt clientID,simxInt jointHandle,simxFloat force,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetJointMaxForce(simxInt clientID,simxInt jointHandle,simxFloat force,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetJointMaxForce(simxInt clientID,simxInt jointHandle,simxFloat* force,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxReadForceSensor(simxInt clientID,simxInt forceSensorHandle,simxUChar* state,simxFloat* forceVector,simxFloat* torqueVector,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxBreakForceSensor(simxInt clientID,simxInt forceSensorHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxReadVisionSensor(simxInt clientID,simxInt sensorHandle,simxUChar* detectionState,simxFloat** auxValues,simxInt** auxValuesCount,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectHandle(simxInt clientID,const simxChar* objectName,simxInt* handle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetVisionSensorImage(simxInt clientID,simxInt sensorHandle,simxInt* resolution,simxUChar** image,simxUChar options,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetVisionSensorImage(simxInt clientID,simxInt sensorHandle,simxUChar* image,simxInt bufferSize,simxUChar options,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetVisionSensorDepthBuffer(simxInt clientID,simxInt sensorHandle,simxInt* resolution,simxFloat** buffer,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectChild(simxInt clientID,simxInt parentObjectHandle,simxInt childIndex,simxInt* childObjectHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectParent(simxInt clientID,simxInt childObjectHandle,simxInt* parentObjectHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxReadProximitySensor(simxInt clientID,simxInt sensorHandle,simxUChar* detectionState,simxFloat* detectedPoint,simxInt* detectedObjectHandle,simxFloat* detectedSurfaceNormalVector,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxLoadModel(simxInt clientID,const simxChar* modelPathAndName,simxUChar options,simxInt* baseHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxLoadUI(simxInt clientID,const simxChar* uiPathAndName,simxUChar options,simxInt* count,simxInt** uiHandles,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxLoadScene(simxInt clientID,const simxChar* scenePathAndName,simxUChar options,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxStartSimulation(simxInt clientID,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxPauseSimulation(simxInt clientID,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxStopSimulation(simxInt clientID,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetUIHandle(simxInt clientID,const simxChar* uiName,simxInt* handle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetUISlider(simxInt clientID,simxInt uiHandle,simxInt uiButtonID,simxInt* position,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetUISlider(simxInt clientID,simxInt uiHandle,simxInt uiButtonID,simxInt position,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetUIEventButton(simxInt clientID,simxInt uiHandle,simxInt* uiEventButtonID,simxInt* auxValues,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetUIButtonProperty(simxInt clientID,simxInt uiHandle,simxInt uiButtonID,simxInt* prop,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetUIButtonProperty(simxInt clientID,simxInt uiHandle,simxInt uiButtonID,simxInt prop,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxAddStatusbarMessage(simxInt clientID,const simxChar* message,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxAuxiliaryConsoleOpen(simxInt clientID,const simxChar* title,simxInt maxLines,simxInt mode,simxInt* position,simxInt* size,simxFloat* textColor,simxFloat* backgroundColor,simxInt* consoleHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxAuxiliaryConsoleClose(simxInt clientID,simxInt consoleHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxAuxiliaryConsolePrint(simxInt clientID,simxInt consoleHandle,const simxChar* txt,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxAuxiliaryConsoleShow(simxInt clientID,simxInt consoleHandle,simxUChar showState,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectOrientation(simxInt clientID,simxInt objectHandle,simxInt relativeToObjectHandle,simxFloat* eulerAngles,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectPosition(simxInt clientID,simxInt objectHandle,simxInt relativeToObjectHandle,simxFloat* position,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectQuaternion(simxInt clientID,simxInt objectHandle,simxInt relativeToObjectHandle,simxFloat* quaternion,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetObjectOrientation(simxInt clientID,simxInt objectHandle,simxInt relativeToObjectHandle,const simxFloat* eulerAngles,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetObjectPosition(simxInt clientID,simxInt objectHandle,simxInt relativeToObjectHandle,const simxFloat* position,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetObjectQuaternion(simxInt clientID,simxInt objectHandle,simxInt relativeToObjectHandle,const simxFloat* quaternion,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetObjectParent(simxInt clientID,simxInt objectHandle,simxInt parentObject,simxUChar keepInPlace,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetUIButtonLabel(simxInt clientID,simxInt uiHandle,simxInt uiButtonID,const simxChar* upStateLabel,const simxChar* downStateLabel,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetLastErrors(simxInt clientID,simxInt* errorCnt,simxChar** errorStrings,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetArrayParameter(simxInt clientID,simxInt paramIdentifier,simxFloat* paramValues,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetArrayParameter(simxInt clientID,simxInt paramIdentifier,const simxFloat* paramValues,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetBooleanParameter(simxInt clientID,simxInt paramIdentifier,simxUChar* paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetBooleanParameter(simxInt clientID,simxInt paramIdentifier,simxUChar paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetIntegerParameter(simxInt clientID,simxInt paramIdentifier,simxInt* paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetIntegerParameter(simxInt clientID,simxInt paramIdentifier,simxInt paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetFloatingParameter(simxInt clientID,simxInt paramIdentifier,simxFloat* paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetFloatingParameter(simxInt clientID,simxInt paramIdentifier,simxFloat paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetStringParameter(simxInt clientID,simxInt paramIdentifier,simxChar** paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetArrayParam(simxInt clientID,simxInt paramIdentifier,simxFloat* paramValues,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetArrayParam(simxInt clientID,simxInt paramIdentifier,const simxFloat* paramValues,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetBoolParam(simxInt clientID,simxInt paramIdentifier,simxUChar* paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetBoolParam(simxInt clientID,simxInt paramIdentifier,simxUChar paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetInt32Param(simxInt clientID,simxInt paramIdentifier,simxInt* paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetInt32Param(simxInt clientID,simxInt paramIdentifier,simxInt paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetFloatParam(simxInt clientID,simxInt paramIdentifier,simxFloat* paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetFloatParam(simxInt clientID,simxInt paramIdentifier,simxFloat paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetStringParam(simxInt clientID,simxInt paramIdentifier,simxChar** paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetCollisionHandle(simxInt clientID,const simxChar* collisionObjectName,simxInt* handle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetDistanceHandle(simxInt clientID,const simxChar* distanceObjectName,simxInt* handle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetCollectionHandle(simxInt clientID,const simxChar* collectionName,simxInt* handle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxReadCollision(simxInt clientID,simxInt collisionObjectHandle,simxUChar* collisionState,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxReadDistance(simxInt clientID,simxInt distanceObjectHandle,simxFloat* minimumDistance,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxCheckCollision(simxInt clientID,simxInt entity1,simxInt entity2,simxUChar* collisionState,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxCheckDistance(simxInt clientID,simxInt entity1,simxInt entity2,simxFloat* minimumDistance,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxRemoveObject(simxInt clientID,simxInt objectHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxRemoveModel(simxInt clientID,simxInt objectHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxRemoveUI(simxInt clientID,simxInt uiHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxCloseScene(simxInt clientID,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjects(simxInt clientID,simxInt objectType,simxInt* objectCount,simxInt** objectHandles,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxDisplayDialog(simxInt clientID,const simxChar* titleText,const simxChar* mainText,simxInt dialogType,const simxChar* initialText,const simxFloat* titleColors,const simxFloat* dialogColors,simxInt* dialogHandle,simxInt* uiHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxEndDialog(simxInt clientID,simxInt dialogHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetDialogInput(simxInt clientID,simxInt dialogHandle,simxChar** inputText,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetDialogResult(simxInt clientID,simxInt dialogHandle,simxInt* result,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxCopyPasteObjects(simxInt clientID,const simxInt* objectHandles,simxInt objectCount,simxInt** newObjectHandles,simxInt* newObjectCount,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectSelection(simxInt clientID,simxInt** objectHandles,simxInt* objectCount,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetObjectSelection(simxInt clientID,const simxInt* objectHandles,simxInt objectCount,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxClearFloatSignal(simxInt clientID,const simxChar* signalName,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxClearIntegerSignal(simxInt clientID,const simxChar* signalName,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxClearInt32Signal(simxInt clientID,const simxChar* signalName,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxClearStringSignal(simxInt clientID,const simxChar* signalName,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetFloatSignal(simxInt clientID,const simxChar* signalName,simxFloat* signalValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetIntegerSignal(simxInt clientID,const simxChar* signalName,simxInt* signalValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetInt32Signal(simxInt clientID,const simxChar* signalName,simxInt* signalValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetStringSignal(simxInt clientID,const simxChar* signalName,simxUChar** signalValue,simxInt* signalLength,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetAndClearStringSignal(simxInt clientID,const simxChar* signalName,simxUChar** signalValue,simxInt* signalLength,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxReadStringStream(simxInt clientID,const simxChar* signalName,simxUChar** signalValue,simxInt* signalLength,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxWriteStringStream(simxInt clientID,const simxChar* signalName,const simxUChar* signalValue,simxInt signalLength,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetFloatSignal(simxInt clientID,const simxChar* signalName,simxFloat signalValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetIntegerSignal(simxInt clientID,const simxChar* signalName,simxInt signalValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetInt32Signal(simxInt clientID,const simxChar* signalName,simxInt signalValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetStringSignal(simxInt clientID,const simxChar* signalName,const simxUChar* signalValue,simxInt signalLength,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxAppendStringSignal(simxInt clientID,const simxChar* signalName,const simxUChar* signalValue,simxInt signalLength,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectFloatParameter(simxInt clientID,simxInt objectHandle,simxInt parameterID,simxFloat* parameterValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetObjectFloatParameter(simxInt clientID,simxInt objectHandle,simxInt parameterID,simxFloat parameterValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectIntParameter(simxInt clientID,simxInt objectHandle,simxInt parameterID,simxInt* parameterValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetObjectIntParameter(simxInt clientID,simxInt objectHandle,simxInt parameterID,simxInt parameterValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectFloatParam(simxInt clientID,simxInt objectHandle,simxInt parameterID,simxFloat* parameterValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetObjectFloatParam(simxInt clientID,simxInt objectHandle,simxInt parameterID,simxFloat parameterValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectInt32Param(simxInt clientID,simxInt objectHandle,simxInt parameterID,simxInt* parameterValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetObjectInt32Param(simxInt clientID,simxInt objectHandle,simxInt parameterID,simxInt parameterValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetModelProperty(simxInt clientID,simxInt objectHandle,simxInt* prop,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSetModelProperty(simxInt clientID,simxInt objectHandle,simxInt prop,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxCreateDummy(simxInt clientID,simxFloat size,const simxUChar* colors,simxInt* objectHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxQuery(simxInt clientID,const simxChar* signalName,const simxUChar* signalValue,simxInt signalLength,const simxChar* retSignalName,simxUChar** retSignalValue,simxInt* retSignalLength,simxInt timeOutInMs);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectGroupData(simxInt clientID,simxInt objectType,simxInt dataType,simxInt* handlesCount,simxInt** handles,simxInt* intDataCount,simxInt** intData,simxInt* floatDataCount,simxFloat** floatData,simxInt* stringDataCount,simxChar** stringData,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetObjectVelocity(simxInt clientID,simxInt objectHandle,simxFloat* linearVelocity,simxFloat* angularVelocity,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxCallScriptFunction(simxInt clientID,const simxChar* scriptDescription,simxInt options,const simxChar* functionName,simxInt inIntCnt,const simxInt* inInt,simxInt inFloatCnt,const simxFloat* inFloat,simxInt inStringCnt,const simxChar* inString,simxInt inBufferSize,const simxUChar* inBuffer,simxInt* outIntCnt,simxInt** outInt,simxInt* outFloatCnt,simxFloat** outFloat,simxInt* outStringCnt,simxChar** outString,simxInt* outBufferSize,simxUChar** outBuffer,simxInt operationMode);   // NOLINT



/* Very first function to call */
EXTAPI_DLLEXPORT simxInt simxStart(const simxChar* connectionAddress,simxInt connectionPort,simxUChar waitUntilConnected,simxUChar doNotReconnectOnceDisconnected,simxInt timeOutInMs,simxInt commThreadCycleInMs);   // NOLINT

/* Very last function to call */
EXTAPI_DLLEXPORT simxVoid simxFinish(simxInt clientID);   // NOLINT

/* The remote API helper functions */
EXTAPI_DLLEXPORT simxInt simxGetPingTime(simxInt clientID,simxInt* pingTime);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetLastCmdTime(simxInt clientID);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSynchronousTrigger(simxInt clientID);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxSynchronous(simxInt clientID,simxUChar enable);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxPauseCommunication(simxInt clientID,simxUChar pause);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetInMessageInfo(simxInt clientID,simxInt infoType,simxInt* info);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetOutMessageInfo(simxInt clientID,simxInt infoType,simxInt* info);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxGetConnectionId(simxInt clientID);   // NOLINT
EXTAPI_DLLEXPORT simxUChar* simxCreateBuffer(simxInt bufferSize);   // NOLINT
EXTAPI_DLLEXPORT simxVoid simxReleaseBuffer(simxUChar* buffer);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxTransferFile(simxInt clientID,const simxChar* filePathAndName,const simxChar* fileName_serverSide,simxInt timeOut,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt simxEraseFile(simxInt clientID,const simxChar* fileName_serverSide,simxInt operationMode);   // NOLINT

/* Following so that we do not have to use thunk files with Matlab 64bit */
EXTAPI_DLLEXPORT simxInt mtlb_simxSetJointPosition(simxInt clientID,simxInt jointHandle,simxFloat* position,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxSetJointTargetVelocity(simxInt clientID,simxInt jointHandle,simxFloat* targetVelocity,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxSetJointTargetPosition(simxInt clientID,simxInt jointHandle,simxFloat* targetPosition,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxSetJointForce(simxInt clientID,simxInt jointHandle,simxFloat* force,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxSetJointMaxForce(simxInt clientID,simxInt jointHandle,simxFloat* force,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxSetFloatSignal(simxInt clientID,const simxChar* signalName,simxFloat* signalValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxSetObjectFloatParameter(simxInt clientID,simxInt objectHandle,simxInt parameterID,simxFloat* parameterValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxSetFloatingParameter(simxInt clientID,simxInt paramIdentifier,simxFloat* paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxSetObjectFloatParam(simxInt clientID,simxInt objectHandle,simxInt parameterID,simxFloat* parameterValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxSetFloatParam(simxInt clientID,simxInt paramIdentifier,simxFloat* paramValue,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxCreateDummy(simxInt clientID,simxFloat* size,const simxUChar* colors,simxInt* objectHandle,simxInt operationMode);   // NOLINT

EXTAPI_DLLEXPORT simxInt mtlb_simxReadProximitySensor(simxInt* clientIDandSensorHandle,simxUChar* detectionState,simxFloat* detectedPoint,simxInt* detectedObjectHandle,simxFloat* detectedSurfaceNormalVector,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxAuxiliaryConsoleOpen(simxInt* clientIDandMaxLinesAndModeAndPositionAndSize,const simxChar* title,simxFloat* textColor,simxFloat* backgroundColor,simxInt* consoleHandle,simxInt operationMode);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxDisplayDialog(simxInt* clientIDandDlgTypeAndOperationMode,const simxChar* titleText,const simxChar* mainText,const simxChar* initialText,const simxFloat* titleColorsAndDlgColors,simxInt* dialogHandleAndUiHandle);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxQuery(simxInt* clientIDandSignalLengthAndTimeOutInMs,const simxChar* signalName,const simxUChar* signalValue,const simxChar* retSignalName,simxUChar** retSignalValue,simxInt* retSignalLength);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxGetObjectGroupData(simxInt* clientIDandObjectTypeAndDataTypeAndOperationMode,simxInt* handlesCountAndIntDataCountAndFloatDataCountAndStringDataCount,simxInt** handles,simxInt** intData,simxFloat** floatData,simxChar** stringData);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxCallScriptFunction_a(const simxInt* variousIntsIn,const simxChar* scriptDescriptionAndFunctionName,const simxInt* inInt,const simxFloat* inFloat,const simxChar* inString,const simxUChar* inBuffer);   // NOLINT
EXTAPI_DLLEXPORT simxInt mtlb_simxCallScriptFunction_b(simxInt clientID,simxInt* variousIntsOut,simxInt** outInt,simxFloat** outFloat,simxChar** outString,simxUChar** outBuffer);   // NOLINT

#ifdef __cplusplus
}
#endif

#endif /* _EXTAPI__ */  // NOLINT
