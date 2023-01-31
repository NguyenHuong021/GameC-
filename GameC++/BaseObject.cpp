#include"BaseObject.h"



BaseObject::BaseObject()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
	p_object_ = NULL;

}

BaseObject::~BaseObject()
{
	if (p_object_ != NULL)
	{
		delete p_object_;
		p_object_ = NULL;
	}
}

bool BaseObject::LoadImg(const char* file_name)
{
	p_object_ = SDLCommonFunction::LoadImg(file_name);
	if (p_object_ == NULL)
	{
		return false;
	}
	return true;
}

void BaseObject::Show(SDL_Surface* des)
{
	if (p_object_ != NULL)
	{
		SDLCommonFunction::ApplySurface(p_object_, des, int x, int y, int w, int h);
	}
}