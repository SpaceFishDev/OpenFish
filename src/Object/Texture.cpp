#include "Texture.h"
SDL_Color GetPixelColor( SDL_Surface* pSurface,  int X,  int Y)
{
  const Uint8 Bpp = pSurface->format->BytesPerPixel;
  Uint8* pPixel = (Uint8*)pSurface->pixels + Y * pSurface->pitch + X * Bpp;

  Uint32 PixelData = *(Uint32*)pPixel;

  SDL_Color Color = {0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE};

  SDL_GetRGB(PixelData, pSurface->format, &Color.r, &Color.g, &Color.b);
  return Color;
}

Color getPixel(Vector2 Position, SDL_Surface* gSurface) {
    SDL_Color c = GetPixelColor(gSurface, Position.x, Position.y);
    return Color(c.r,c.g,c.b);
}