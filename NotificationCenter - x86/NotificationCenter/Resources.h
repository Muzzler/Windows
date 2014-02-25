
#include "../../../Aurora-SDK/Include/A2DResources.h"

A2D_XL_RESOURCES(
	A2D_XL_FRAMES(
		A2D_XL_DEFINE_FRAME(1,
			A2D_XL_DRAWABLES(
				A2D_XL_DEFINE_DRAWABLE(wallpaper)
				A2D_XL_DEFINE_DRAWABLE(data)
				A2D_XL_DEFINE_DRAWABLE(profilePicture)
			)
		)
		A2D_XL_DEFINE_FRAME(2,
			A2D_XL_DRAWABLES(
				A2D_XL_DEFINE_DRAWABLE(wallpaper)
				A2D_XL_DEFINE_DRAWABLE(data)
				A2D_XL_DEFINE_DRAWABLE(profilePicture)
			)
		)
	)
)

Drawable x = R::frames::$1::drawables::wallpaper;
Drawable x2 = R::frames::$2::drawables::wallpaper;