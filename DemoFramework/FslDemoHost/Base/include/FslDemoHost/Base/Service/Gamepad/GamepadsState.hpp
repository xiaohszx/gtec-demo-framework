#ifndef FSLDEMOHOST_BASE_SERVICE_GAMEPAD_GAMEPADSSTATE_HPP
#define FSLDEMOHOST_BASE_SERVICE_GAMEPAD_GAMEPADSSTATE_HPP
/****************************************************************************************************************************************************
* Copyright 2017 NXP
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*    * Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*
*    * Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*
*    * Neither the name of the NXP. nor the names of
*      its contributors may be used to endorse or promote products derived from
*      this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************************************************************************************/

#include <FslDemoApp/Base/Service/Gamepad/GamepadDeadZoneType.hpp>
#include <FslDemoApp/Base/Service/Gamepad/GamepadState.hpp>
#include <FslDemoApp/Base/Service/NativeWindowEvents/INativeWindowEventListener.hpp>
#include <memory>
#include <vector>

namespace Fsl
{
  class GamepadsState : public INativeWindowEventListener
  {
    std::vector<GamepadState> m_gamepads;
    GamepadDeadZoneType m_deadZoneType;
    bool m_isConfigured;
  public:
    GamepadsState();

    bool IsConfigured() const
    {
      return m_isConfigured;
    }

    GamepadDeadZoneType GetDeadZoneType() const
    {
      return m_deadZoneType;
    }
    void SetDeadZoneType(const GamepadDeadZoneType type);

    uint32_t GetCount() const;
    GamepadState GetState(const uint32_t gamepadIndex) const;

    // From INativeWindowEventListener
    virtual void OnNativeWindowEvent(const NativeWindowEvent& event) override;
  };
}

#endif