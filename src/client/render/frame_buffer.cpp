#include "frame_buffer.hpp"

FrameBuffer::FrameBuffer() {
    // Create a texture object
    glGenTextures(1, &textureId[0]);
    glBindTexture(GL_TEXTURE_RECTANGLE, textureId[i]);
    glTexParameterf(GL_TEXTURE_RECTANGLE, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_RECTANGLE, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //glTexImage2D( GL_TEXTURE_RECTANGLE, 0, GL_RGBA32F, INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT, 0, GL_RGBA, GL_FLOAT, 0 );
    glTexImage2D(GL_TEXTURE_RECTANGLE, 0, GL_RGBA32F, 2048, 2048, 0, GL_RGBA, GL_FLOAT, 0);

    // Create a renderbuffer object to store depth info
    glGenRenderbuffers(1, &renderbufferId);
    glBindRenderbuffer(GL_RENDERBUFFER, renderbufferId);
    //glRenderbufferStorage( GL_RENDERBUFFER, GL_DEPTH_COMPONENT, INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT );
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, 2048, 2048);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    // Create a framebuffer object
    glGenFramebuffers(1, &framebufferId);
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);

    // Attach the texture object to the framebuffer color attachment point
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_RECTANGLE, textureId[0], 0);

    // Attach the renderbuffer to the framebuffer depth attachment point
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderbufferId);

    // Check status
    checkFramebufferStatus();

    // Switch back to window-system-provided framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}