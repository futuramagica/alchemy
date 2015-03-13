#ifndef RENDERER_H
#define RENDERER_H
struct RectangleInfo
{
public:
	int x;
	int y;
	int width;
	int height;
	float thickness;
};
class Renderer
{
public:
	void DrawRectangle(RectangleInfo* info);
	Renderer(int w,int h);
private:
	int height;
	int width;
};

#endif