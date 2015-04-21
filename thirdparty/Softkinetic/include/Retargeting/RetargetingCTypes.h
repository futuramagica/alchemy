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


#ifndef RETARGETING_CTYPES_H
#define RETARGETING_CTYPES_H


#include "RetargetingPlatform.h"


/**
 * \file RetargetingCTypes.h
 *
 * \brief Retargeting Types
 */


/**
 * \brief Predefined keypoints.
 *
 * \note These are used to identify the keypoints of the core model.
 */
typedef enum
{
	SKA_PELVIS = 0,
	SKA_SPINE_1 = 1,
	SKA_SPINE_2 = 2,
	SKA_NECK = 3,
	SKA_HEAD = 4,

	SKA_RIGHT_SHOULDER = 5,
	SKA_RIGHT_ELBOW = 6,
	SKA_RIGHT_WRIST = 7,
	SKA_RIGHT_FINGERS = 8,

	SKA_RIGHT_HIP = 9,
	SKA_RIGHT_KNEE = 10,
	SKA_RIGHT_ANKLE = 11,
	SKA_RIGHT_TOES = 12,

	SKA_LEFT_SHOULDER = 13,
	SKA_LEFT_ELBOW = 14,
	SKA_LEFT_WRIST = 15,
	SKA_LEFT_FINGERS = 16,

	SKA_LEFT_HIP = 17,
	SKA_LEFT_KNEE = 18,
	SKA_LEFT_ANKLE = 19,
	SKA_LEFT_TOES = 20,

	SKA_KEYPOINTS_COUNT // 21.

} SKA_Keypoint;


/**
 * \brief Keypoints labels.
 *
 * \note Default value for the user joints map. It is provided to ska_createCharacter() when using the default rig.
 */
static const char* SKA_KeypointLabels[SKA_KEYPOINTS_COUNT] =
{
	"Pelvis",
	"Spine1",
	"Spine2",
	"Neck",
	"Head",

	"RightShoulder",
	"RightElbow",
	"RightWrist",
	"RightFingers",

	"RightHip",
	"RightKnee",
	"RightAnkle",
	"RightToes",

	"LeftShoulder",
	"LeftElbow",
	"LeftWrist",
	"LeftFingers",

	"LeftHip",
	"LeftKnee",
	"LeftAnkle",
	"LeftToes"
};


/**
 * \brief Default user-rig file.
 *
 * \note If this is used in ska_createCharacter() then the default user rig is used.
 */
static const char* SKA_DefaultUserRig = 0;


/**
 * \brief Default root joint name.
 */
static const char* SKA_DefaultRootJointName = SKA_KeypointLabels[SKA_PELVIS];


/**
 * \brief Canonic axes.
 */
typedef enum
{
	SKA_X_AXIS = 0,
	SKA_Y_AXIS = 1,
	SKA_Z_AXIS = 2,

	SKA_X_REVERSE_AXIS = 3,
	SKA_Y_REVERSE_AXIS = 4,
	SKA_Z_REVERSE_AXIS = 5,

	SKA_CANONIC_AXES_NUM // 6.

} SKA_CanonicAxis;


/**
 * \brief Handedness conversion modes.
 */
typedef enum
{
	SKA_RIGHT_HANDED = 0,

	SKA_LEFT_HANDED_INVERSE_X = 1,
	SKA_LEFT_HANDED_INVERSE_Y = 2,
	SKA_LEFT_HANDED_INVERSE_Z = 3,

	SKA_LEFT_HANDED_SWAP_XY = 4,
	SKA_LEFT_HANDED_SWAP_YZ = 5,
	SKA_LEFT_HANDED_SWAP_ZX = 6,

	SKA_HANDEDNESS_COUNT // 7.

} SKA_Handedness;


/**
 * \brief A 3D position structure.
 */
struct SKA_Position
{
	float x;
	float y;
	float z;
};


/**
 * \brief A quaternion structure.
 *
 * \note This structure represents rotations or orientations.
 */
struct SKA_Quaternion
{
	float x;
	float y;
	float z;
	float w;
};


/**
 * \brief A 6D frame structure.
 *
 * \note This is a SKA_Position together with a SKA_Quaternion. Positions in the space of 3D points use SKA_Position,
 *       whereas positions in the space of 6D rigid bodies use SK_Frame.
 */
struct SKA_Frame
{
	SKA_Quaternion quat;
	SKA_Position pos;
};


/**
 * \brief A 6D frame structure including scaling information.
 *
 * \note This is a SKA_Position together with a SKA_Quaternion and a scale. This is an extended SKA_Frame including
 *       scaling information.
 */
struct SKA_ScaledFrame
{
	SKA_Quaternion quat;
	SKA_Position pos;
	float scale;
};


/**
 * \brief Creation argument structure for joints.
 *
 * \note This struct specifies the selected root joint (out of all the joints in the Collada file) and the joints
 *       mapping. Array 'userJointMap' must have a size of SKA_KEYPOINTS_COUNT.
 */
struct SKA_SettingsUserJoint
{
	const char* rootJointName;
	const char** userJointMap;
};


static SKA_SettingsUserJoint SKA_DefaultSettingsUserJoint = {SKA_DefaultRootJointName, SKA_KeypointLabels};


/**
 * \brief Creation argument structure for the user frame coordinate system.
 *
 * \note This struct only specifies the front vector and origin as the up vector is read from the Collada file.
 */
struct SKA_SettingsUserFrame
{
	SKA_CanonicAxis frontVector;
	SKA_Position userOrigin;
};


static SKA_SettingsUserFrame SKA_DefaultSettingsUserFrame = {SKA_Y_REVERSE_AXIS, 0.0f, 0.0f, 0.0f};


/**
 * \brief Distance units.
 */
typedef enum
{
	SKA_MILLIMETERS = 0,
	SKA_CENTIMETERS = 1,
	SKA_METERS = 2,
	SKA_INCHES = 3,
	SKA_FEET = 4,
	SKA_YARDS = 5,

	SKA_DISTANCE_UNITS_COUNT // 6.

} SKA_DistanceUnit;


/**
 * \brief Output frames modes.
 */
typedef enum
{
	SKA_GLOBAL = 0,
	SKA_LOCAL = 1,
	SKA_PARAMS = 2,

	SKA_OUTPUT_FRAMES_MODES_COUNT // 3.

} SKA_OutputFramesMode;


/**
 * \brief Used to specify "all created characters" in some functions.
 *
 * \note This is used in ska_retarget() or ska_destroy() for example.
 */
#define SKA_ALL_CHARACTERS UINT32_MAX


/**
 * \brief Returned by function ska_createCharacter() if an error occurred during the character creation.
 */
#define SKA_INVALID_CHARACTER UINT16_MAX


/**
 * \brief Represents all the possible errors that can occur on the retargeting API.
 *
 * \note There are error messages associated to each of these SKA_ErrorType. They can be retrieved using function
 *       ska_getErrorMessage().
 */
typedef enum
{
	SKA_NO_ERROR = 0,

	SKA_IMPORT_FILE_NOT_FOUND = 1,
	SKA_IMPORT_FILE_NOT_FORMATTED_AS_EXPECTED = 2,
	SKA_IMPORT_UP_AND_FRONT_AXES_ARE_ALIGNED = 3,
	SKA_IMPORT_UNHANDLED_UP_VECTOR = 4,
	SKA_IMPORT_UNNAMED_JOINT = 5,
	SKA_IMPORT_EMPTY_ROOT_JOINT_NAME = 6,
	SKA_IMPORT_NO_ROOT_JOINT_IN_FILE = 7,
	SKA_IMPORT_UNKNOWN_JOINT = 8,
	SKA_IMPORT_USER_JOINT_MAPPED_TWICE = 9,
	SKA_IMPORT_EMPTY_JOINT_MAP = 10,
	SKA_IMPORT_CANNOT_INSTANTIATE_JOINT = 11,
	SKA_IMPORT_NON_UNIFORM_SCALES_NOT_HANDLED = 12,
	SKA_IMPORT_CORRUPTED_PARAMETER = 13,
	SKA_IMPORT_INPUT_BUFFER_CORRUPTED = 14,
	SKA_IMPORT_NOT_ALL_JOINTS_ARE_MAPPED = 15,
	SKA_IMPORT_JOINTS_ASSOCIATION_CORRUPTION = 16,
	SKA_IMPORT_UNKNOWN_ERROR = 17,

	SKA_CHARACTER_NOT_FOUND = 18,
	SKA_INVALID_SCALING_FACTOR = 19,
	SKA_UNKNOWN_ERROR = 20,

	SKA_ERRORS_COUNT // 21.
} SKA_ErrorType;


/**
 * \brief Callback function signature used to be notified about log information.
 *
 * \note Such a callback function pointer is intended to be provided to function ska_option_setLoggingListener().
 */
typedef void (SKA_SDK_CDECL *SKA_LoggingListener)(const char *);


#endif //RETARGETING_CTYPES_H
