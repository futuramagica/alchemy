/*************************************************************************************************************************/
//  SOFTKINETIC DISCLAIMER
//
// COPYRIGHT AND CONFIDENTIALITY NOTICE – SOFTKINETIC CONFIDENTIAL INFORMATION      
// The source code of the SoftKinetic Retargeting SDK is proprietary and confidential information of Softkinetic Software SA
// All rights reserved to SOFTKINETIC SOFTWARE SA (a company incorporated and existing under the laws of Belgium, with 
// its principal place of business at Boulevard de la Plainelaan 15, 1050 Brussels (Belgium), registered with the Crossroads 
// bank for enterprises under company number 0890 705 864 - “Softkinetic Software”)
//
// For any question about terms and conditions, please contact: info@softkinetic.com
// Copyright (c) 2002-2013 Softkinetic Software SA
/*************************************************************************************************************************/


#ifndef RETARGETING_CAPI_OPTIONS_H
#define RETARGETING_CAPI_OPTIONS_H


#include "RetargetingPlatform.h"
#include "RetargetingCTypes.h"


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


/**
 * \file RetargetingCAPIOptions.h
 *
 * \brief API Options parameters documentation.
 */


/*************************************************************************
 *                             PARAMETERS                                *
 *************************************************************************/


/**
 * \brief Specify the source coordinate system.
 *
 * \param[in] handedness     Source handedness conversion mode.
 * \param[in] worldFrame     Source world frame.
 * \param[in] distanceUnit   The unit in which the positions are expressed.
 * 
 * \note The handedness conversion mode is used when the source coordinate system is left handed. The source world
 *       frame is the frame in which the motion captured keypoint positions are expressed. This frame should be provided
 *       with respect to the core retargeting frame (look at the User Guide for more details).
 */
SKA_DLL_API void SKA_SDK_CDECL ska_option_setSourceCoordinateSystem(SKA_Handedness handedness, SKA_Frame worldFrame, SKA_DistanceUnit distanceUnit);


/**
 * \brief Specify the target coordinate system.
 *
 * \param[in] distanceUnit   The unit in which the positions are expressed.
 * \param[in] worldFrame     Target world frame.
 * \param[in] handedness     Target handedness conversion mode.
 *
 * \note The target coordinate system is the frame in which the output target joint frames are expressed. It should be
 *       provided with respect to the core retargeting frame (look at the User Guide for more details). The handedness
 *       conversion mode is used when the target coordinate system is left handed.
 */
SKA_DLL_API void SKA_SDK_CDECL ska_option_setTargetCoordinateSystem(SKA_DistanceUnit distanceUnit, SKA_Frame worldFrame, SKA_Handedness handedness);


/**
 * \brief Enables automatic source scaling.
 *
 * \param[in] characterId   Character id
 * \param[in] enable        Enable.
 *
 * \note This function allows to rescale the source keypoints so that the source height is the same as the one of the
 *       user rig.
 */
SKA_DLL_API void SKA_SDK_CDECL ska_option_enableAutomaticSourceScaling(uint characterId, bool enable);


/**
 * \brief Enables retargeting of hands and feet.
 *
 * \param[in] characterId		Character id
 * \param[in] retargetHands		Enable retargeting of the hands.
 * \param[in] retargetFeet		Enable retargeting of the feet.
 *
 * \note Retargeting hands and feet allows to align the target's hand or feet on the source pose. This feature is
 *       disabled by default.
 */
SKA_DLL_API void SKA_SDK_CDECL ska_option_enableExtremities(uint characterId, bool retargetHands, bool retargetFeet);


/**
 * \brief Enables joint-space stabilization.
 *
 * \param[in] characterId        Character id.
 * \param[in] useStabilization   Enable or not.
 *
 * \note Joint-space stabilization does not modify the length of the bones. It does not stabilize the position of the
 *       joints directly but the joint parameters. 
 */
SKA_DLL_API void SKA_SDK_CDECL ska_option_enableStabilization(uint characterId, bool useStabilization);


/**
 * \brief Parametrize joint-space stabilization.
 *
 * \param[in] characterId                      Character id.
 * \param[in] stabilizationDistanceThreshold   The distance below which the filtering becomes active.
 * \param[in] stabilizationPower               The strength of the stabilization.
 *
 * \note Joint-space stabilization does not modify the length of the bones. It does not stabilize the position of the
 *       joints directly but the joint parameters.
 *       This option only filters small displacements. This is so that large displacements are considered meaningful
 *       but small displacements are considered to be mainly noise.
 */
SKA_DLL_API void SKA_SDK_CDECL ska_option_setStabilizationParameters(uint characterId, float stabilizationDistanceThreshold, float stabilizationPower);


/**
 * \brief Edit the default source pose.
 *
 * \param[in]		characterId		Character id.
 * \param[in]		keypointIndex	Keypoint around which to rotate.
 * \param[in]		quat			Rotation to perform.
 *
 * \note The default source pose is the source pose that has the system output the default target rig. The default
 *       behavior is to have a default source pose and a default target rig that look alike. This function allows to
 *       modify the default source pose. So in order to output the default target rig one no longer has to input the
 *       very same pose. A use-case of this pose offset is to output a hunchbacked target rig out of a straight input
 *       pose, for example. A normal person in its usual comfy pose can now drive a digital stooped elderly or monster.
 *       Look at the User Guide for more details.
 *       This function modifies the default source pose. The user needs to specify a center keypoint around which to
 *       rotate and a quaternion. The function then rotates the children keypoints accordingly around the specified
 *       center keypoint.
 *       e.g. when you rotate around a shoulder, then the elbow, wrist and fingers should move accordingly. This
 *       function does all this work for you.
 */
SKA_DLL_API void SKA_SDK_CDECL ska_option_editDefaultSourcePose(uint characterId, SKA_Keypoint keypointIndex, SKA_Quaternion quat);


/**
 * \brief Resets the default source pose.
 *
 * \param[in] characterId   Character id.
 *
 * \note Brings the system back to its default behavior where the source pose has to look like the default target rig in
 *       order for the system to output this default target rig.
 */
SKA_DLL_API void SKA_SDK_CDECL ska_option_resetDefaultSourcePose(uint characterId);


/*************************************************************************
 *                             UTILITIES                                 *
 *************************************************************************/


/**
 * \brief Allows to enable/disable the logger.
 *
 * \param[in] enable   Boolean that enables/disables the logger.
 */
SKA_DLL_API void SKA_SDK_CDECL ska_option_enableLogging(bool enable);


/**
 * \brief Allows to listen to logging events.
 *
 * \param[in|out] loggingListener   Callback function which will receive log info.
 *
 * \note This function should be the first one called, even before ska_createCharacter(). The user-defined callback is
 *       provided with the log messages as a char* and can display or store them the way he likes.
 */
SKA_DLL_API void SKA_SDK_CDECL ska_option_setLoggingListener( SKA_LoggingListener loggingListener );


#ifdef __cplusplus
} // extern C
#endif // __cplusplus


#endif // RETARGETING_CAPI_OPTIONS_H