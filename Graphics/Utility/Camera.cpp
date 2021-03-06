#include "Camera.h"

#include "../Meshes/SubMesh.h"

/*
Polls the camera for keyboard / mouse movement.
Should be done once per frame! Pass it the msec since
last frame (default value is for simplicities sake...)
*/
void Camera::updateCamera(float msec) {
	//Bounds check the pitch, to be between straight up and straight down ;)
	pitch = min(pitch, 90.0f);
	pitch = max(pitch, -90.0f);

	if (yaw <0) {
		yaw += 360.0f;
	}
	if (yaw > 360.0f) {
		yaw -= 360.0f;
	}

	//std::cout << "yaw   : " << yaw << std::endl;
	//std::cout << "pitch : " << pitch << std::endl;
}

bool Camera::subMeshIsInCameraView(SubMesh* submesh)
{
	const Vector3 position = submesh->GetTransform().getPositionVector();
	const float radius = submesh->GetBoundingRadius();

	return viewFrustum.insideFrustum(position, radius);
}

/*
Generates a view matrix for the camera's viewpoint. This matrix can be sent
straight to the shader...it's already an 'inverse camera' matrix.
*/
Matrix4 Camera::buildViewMatrix() {
	//Why do a complicated matrix inversion, when we can just generate the matrix
	//using the negative values ;). The matrix multiplication order is important!
	Matrix4 matrix = Matrix4::rotation(-pitch, Vector3(1, 0, 0)) *
		Matrix4::rotation(-yaw, Vector3(0, 1, 0)) *
		Matrix4::translation(-position);

	viewMatrix = matrix;

	return matrix;
}

void Camera::updateViewFrustum(Matrix4& projectionMatrix)
{
	viewFrustum.fromMatrix(projectionMatrix * viewMatrix);
};
