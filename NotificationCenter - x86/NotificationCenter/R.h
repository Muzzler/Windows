
typedef void** Image;

struct R
{
	struct Images
	{
		const static Image wallpaper;
		const static Image defaultProfilePicture;
	};
	
	static Images images;
}

#define PreloadImageResource(x, y)		G_SAFELY(Toolkit::preload(x, y))

PreloadImageResource(R::images.wallpaper, "C://Source//Whats up!");
PreloadImageResource(R::images.wallpaper, "C://Source//Whats up!");
PreloadImageResource(R::images.wallpaper, "C://Source//Whats up!");
PreloadImageResource(R::images.wallpaper, "C://Source//Whats up!");
