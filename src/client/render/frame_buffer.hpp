#ifndef FRAME_BUFFER_H
#define FRAME_BUFFER_H

namespace UnifiedRender {
class FrameBuffer {
   public:
    FrameBuffer();

   private:
    int numTextures 4;
    GLuint framebufferId;
	Gluint renderbufferId;
	Gluint textureId[numTextures];
}
#endif