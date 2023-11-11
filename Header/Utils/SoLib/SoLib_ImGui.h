#pragma once
#include <stdint.h>
#include <imgui.h>

#include "SoLib_Traits.h"	// 型情報など

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"


namespace SoLib {

	// ImGuiの前方宣言
	template<IsNotPointer T>
	bool ImGuiWidget(const char *const label, T *const value);

	template <>
	bool ImGuiWidget<bool>(const char *const label, bool *const value);

	template <>
	bool ImGuiWidget<int32_t>(const char *const label, int32_t *const value);
	template <>
	bool ImGuiWidget<float>(const char *const label, float *const value);
	template <>
	bool ImGuiWidget<double>(const char *const label, double *const value);
	template <>
	bool ImGuiWidget<Vector2>(const char *const label, Vector2 *const value);
	template <>
	bool ImGuiWidget<Vector3>(const char *const label, Vector3 *const value);
	template <>
	bool ImGuiWidget<Vector4>(const char *const label, Vector4 *const value);

	bool ImGuiWidgetAngle(const char *const label, float *const value, float min = -360.f, float max = +360.f);

}