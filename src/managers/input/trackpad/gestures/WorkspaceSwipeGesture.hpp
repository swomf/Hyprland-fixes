#pragma once

#include "ITrackpadGesture.hpp"
#include "../../../../desktop/DesktopTypes.hpp"

class CWorkspaceSwipeGesture : public ITrackpadGesture {
  public:
    // step: how many workspace IDs a full swipe jumps. 1 = classic adjacent swipe, >1 = grid row/column jump.
    CWorkspaceSwipeGesture(int step = 1) : m_step(step) {}
    virtual ~CWorkspaceSwipeGesture() = default;

    virtual void begin(const ITrackpadGesture::STrackpadGestureBegin& e);
    virtual void update(const ITrackpadGesture::STrackpadGestureUpdate& e);
    virtual void end(const ITrackpadGesture::STrackpadGestureEnd& e);

    virtual bool isDirectionSensitive();

  private:
    int m_step = 1;
};
