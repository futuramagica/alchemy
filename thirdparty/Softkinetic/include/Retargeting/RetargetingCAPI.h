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


#ifndef RETARGETING_CAPI_H
#define RETARGETING_CAPI_H


#include "RetargetingPlatform.h"
#include "RetargetingCTypes.h"


/**
 * \mainpage Retargeting Documentation
 *
 * \section Introduction
 *
 * The Retargeting System&trade; links the motion capture chain to your game engine. It allows to apply mocap data
 * output by an engine such as iisu&reg; directly to your skinned character out of the box.\htmlonly <br> \endhtmlonly
 * In order to do so it adapts the data streamed out of your motion capture solution to your own character rig and
 * computes the 6D position and orientation for each joint in your rig out of the 3D keypoints position provided by the
 * mocap engine.\htmlonly <br> \endhtmlonly
 * Please refer to the User Guide for more information.
 *
 * \image html illustration.png
 *
 */


/**
 * \file RetargetingCAPI.h
 * \brief API documentation
 */


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


/*************************************************************************
 *                             CREATION                                 *
 *************************************************************************/


/**
 * \brief Imports and loads a target rig. This is a user-defined character rig read out of a Collada file.
 *
 * \param[in] colladaFile          Path of the Collada file containing the description of the user rig.
 * \param[in] settingsUserJoints   Joints settings containing the root joint name and the joints map.
 * \param[in] settingsUserFrame    Frame settings containing the user frame's front-vector and its position with respect to the core retargeting frame.
 * \return Character id identifying the created character.
 *
 * \warning If an error occurs, it is stacked and can be popped out using ska_popLastErrorId().
 * 
 * \note There can be several characters defined in the Collada file, the one rig to load out is selected
 *       via its root joint name.
 */
SKA_DLL_API uint SKA_SDK_CDECL ska_createCharacter(const char *colladaFile = SKA_DefaultUserRig, const SKA_SettingsUserJoint* settingsUserJoints = &SKA_DefaultSettingsUserJoint, const SKA_SettingsUserFrame* settingsUserFrame = &SKA_DefaultSettingsUserFrame);

/*************************************************************************
 *                         RUN-TIME                                     *
 *************************************************************************/


/**
 * \brief Sets the position of the source keypoints.
 *
 * \param[in] characterId   Character id.
 * \param[in] keypoints     Array of 3D position keypoints defining a source pose.
 *
 * \note The positions are expressed in the source world frame. This source world frame is specified by function
 *       ska_option_setSourceCoordinateSystem(). The number of joints is given by SKA_KEYPOINTS_COUNT (21) and their
 *       order is provided by the enums SKA_Keypoint.
 */
SKA_DLL_API void SKA_SDK_CDECL ska_setSourceKeypoints(uint characterId, const SKA_Position keypoints[SKA_KEYPOINTS_COUNT]);


/**
 * \brief Executes the retargeting process.
 *
 * \param[in] characterId   Character id. Processes all created characters by default.
 */
SKA_DLL_API void SKA_SDK_CDECL ska_retarget(uint characterId = SKA_ALL_CHARACTERS);


/*************************************************************************
 *                           OUTPUT                                     *
 *************************************************************************/

/**
 * \brief  Returns the error id related to the latest stacked error.
 *
 * \return SKA_ErrorType (if no error, returns SKA_NO_ERROR).
 *
 * \note This function pops errors out of a stack so you do not have to check the errors each time you call a
 *       retargeting function.
 */
SKA_DLL_API SKA_ErrorType SKA_SDK_CDECL ska_popLastErrorId();


/**
 * \brief Returns the error message associated to the error type provided as input.
 *
 * \param[in] errorType   Error Type.
 */
SKA_DLL_API const char * SKA_SDK_CDECL ska_getErrorMessage(SKA_ErrorType errorType);


/**
 * \brief Returns the number of user joints.
 *
 * \param[in] characterId   Character id.
 * \return Joints number.
 *
 * \note This is the number of joint names and frames returned by ska_getTargetJointsOrder() and ska_getTargetJointsFrames().
 */
SKA_DLL_API uint SKA_SDK_CDECL ska_getTargetJointsCount(uint characterId);


/**
 * \brief Provides the joint frames output order as an array of strings.
 *
 * \param[in] characterId   Character id.
 * \return Array of strings (the number of which is the number of joints provided by ska_getTargetJointsCount()).
 *
 * \note The user-rig has a number of joints and a structure that depends on the person who creates the
 *       rig (the animator), so the joints that exist in a target rig are not predefined (ie: a user-rig
 *       may have complex fingers and another one may only have a single joint for the whole hand,
 *       depending on the animator's will).
 *       Now, when the target joints output frames are returned, they are provided in an array which order
 *       depends on the number and structure of the user joints (this order is determined automatically
 *       by the system). That is the order of the joints in the array is target-rig dependent. So
 *       in order for the coders using to know which index of the array corresponds to which user joint, we
 *       return the target joint names in an array, in the same order as the one used to return target-rig
 *       output frames.
 *       This order does not change during a session so the user needs to do the mapping between the user joint
 *       indices in the return arrays and his own data structure for joints only once at init.
 */
SKA_DLL_API const char ** SKA_SDK_CDECL ska_getTargetJointsOrder(uint characterId);


/**
 * \brief Returns the target joints output frames as an array of SK_Frame.
 *
 * \param[in] characterId		Character id.
 * \param[in] outputFramesMode	Reference frame with respect to which the output joint frames are expressed.
 * \return Array of SK_Frame.
 *
 * \note The number of joints in the array is provided by ska_getTargetJointsCount() and the order of the joints the
 *       frames belong to is provided by ska_getTargetJointsOrder(). As an example, if you want to know which joint the
 *       fifth returned frame belongs to then you have to look for the fifth joint's user name in the array of joint
 *       names returned by ska_getTargetJointsOrder().
 *       The frames can expressed in the target world frame (if outputFramesMode = SKA_GLOBAL), locally with respect to
 *       their parent frame (outputFramesMode = SKA_LOCAL) or only the joints parameters are output (if
 *       outputFramesMode = SKA_GLOBAL).
 *       Note that the target world frame is specified by function ska_option_setTargetCoordinateSystem(). 
 */
SKA_DLL_API const SKA_ScaledFrame * SKA_SDK_CDECL ska_getTargetJointsFrames(uint characterId, SKA_OutputFramesMode outputFramesMode = SKA_GLOBAL);


/**
 * \brief Destroys characters.
 *
 * \param[in] characterId   Character id. Destroys all created characters by default.
 *
 * \note It is not mandatory to call it as all the allocated memory will be cleaned by the API itself.
 */
SKA_DLL_API void SKA_SDK_CDECL ska_destroy(uint characterId = SKA_ALL_CHARACTERS);

#ifdef __cplusplus
} // extern C
#endif // __cplusplus


#endif // RETARGETING_CAPI_H