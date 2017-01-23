// vive-diy-position-sensor-geometry-getter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	vr::HmdError err;
	vr::IVRSystem *vrSystem = vr::VR_Init(&err, vr::EVRApplicationType::VRApplication_Scene);

	vr::TrackedDevicePose_t pose_array[vr::k_unMaxTrackedDeviceCount];
	vrSystem->GetDeviceToAbsoluteTrackingPose(vr::TrackingUniverseOrigin::TrackingUniverseStanding, 0.0f, pose_array, vr::k_unMaxTrackedDeviceCount);

	int idx = 0;
	for (vr::TrackedDeviceIndex_t i = 0; i < vr::k_unMaxTrackedDeviceCount; i++) {
		vr::TrackedDevicePose_t pose = pose_array[i];
		if (pose.bPoseIsValid && vrSystem->GetTrackedDeviceClass(i) == vr::TrackedDeviceClass::TrackedDeviceClass_TrackingReference) {
			vr::HmdMatrix34_t &m = pose.mDeviceToAbsoluteTracking;
			printf("b%d origin %f %f %f matrix %f %f %f %f %f %f %f %f %f\n", idx++,
				m.m[0][3], m.m[1][3], m.m[2][3],
				m.m[0][0], m.m[0][1], m.m[0][2], m.m[1][0], m.m[1][1], m.m[1][2], m.m[2][0], m.m[2][1], m.m[2][2]);
		}
	}

	system("pause");

	vr::VR_Shutdown();
    return 0;
}

