#pragma once

#include <optional>

#include "../../helpers/memory/Memory.hpp"
#include "../../desktop/DesktopTypes.hpp"

class CUnifiedWorkspaceSwipeGesture {
  public:
    // step: how many workspace IDs a full swipe jumps (1 = classic adjacent swipe, >1 = grid row/column jump).
    // vertical: force the swipe axis (true = vertical, false = horizontal). If unset, falls back to the global
    //           `workspaces` animation style (slidevert -> vertical), preserving legacy behavior.
    void begin(int step = 1, std::optional<bool> vertical = std::nullopt);
    void update(double delta);
    void end();

    bool isGestureInProgress();

  private:
    PHLWORKSPACE        m_workspaceBegin = nullptr;
    PHLMONITORREF       m_monitor;

    int                 m_step     = 1;
    std::optional<bool> m_vertical = std::nullopt;

    double              m_delta            = 0;
    int                 m_initialDirection = 0;
    float               m_avgSpeed         = 0;
    int                 m_speedPoints      = 0;
    int                 m_touchID          = 0;

    friend class CWorkspaceSwipeGesture;
    friend class CInputManager;
};

inline UP<CUnifiedWorkspaceSwipeGesture> g_pUnifiedWorkspaceSwipe = makeUnique<CUnifiedWorkspaceSwipeGesture>();
