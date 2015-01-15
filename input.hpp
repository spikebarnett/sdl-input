#ifndef __spikec_input
#define __spikec_input

#include "inputcodes.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <list>
#include <cmath>
#include <algorithm>

int LastLAT = -32000;
int LastRAT = -32000;
int LastLAX = 0;
int LastLAY = 0;
int LastRAX = 0;
int LastRAY = 0;

const int TThresh = -16000;
const int SDead  =  8000;
const int SThresh =  24000;
const int Input_Event_Max = 20;

SDL_Joystick *Controller = NULL;
int Input_State[I_END];
std::list<Input_Enum> Input_Event_List;

void Controller_Open ()
{
  if( SDL_NumJoysticks() > 0 )
  {
    Controller = SDL_JoystickOpen (0);
  }
}

Input_Enum Input_Event(Input_Enum i)
{
  if ( i == UNKNOWN ) return i;
  Input_Event_List.push_back(i);
  if ( Input_Event_List.size() > Input_Event_Max ) Input_Event_List.pop_front();
  return i;
};

void Input_Set_Keyboard_State(Input_Enum i, int v)
{
  Input_State[i] = v;
}

bool Input_Event_Check_Patern (std::list<Input_Enum> &patern)
{
  std::list<Input_Enum>::iterator pos = std::search(Input_Event_List.begin(), Input_Event_List.end(), patern.begin(), patern.end());
  if(pos == Input_Event_List.end())
  {
    return false;
  }
  Input_Event_List.clear();
  return true;
}

void Print_Input_Event_List()
{
  for (std::list<Input_Enum>::const_iterator iterator = Input_Event_List.begin(), end = Input_Event_List.end(); iterator != end; ++iterator)
  {
    std::cout << Input_Name(*iterator) << ",";
  }
  std::cout << "\n";
}

void Input_Set_Controller_State ()
{
  std::string name = SDL_JoystickName(Controller);
  if ( name == "Sony PLAYSTATION(R)3 Controller" )
  {
    Input_State[C_MOVEX] = (abs(SDL_JoystickGetAxis(Controller, 0)) > SDead)?SDL_JoystickGetAxis(Controller, 0):0;
    Input_State[C_MOVEY] = (abs(SDL_JoystickGetAxis(Controller, 1)) > SDead)?SDL_JoystickGetAxis(Controller, 1):0;
    Input_State[C_LOOKX] = (abs(SDL_JoystickGetAxis(Controller, 2)) > SDead)?SDL_JoystickGetAxis(Controller, 2):0;
    Input_State[C_LOOKY] = (abs(SDL_JoystickGetAxis(Controller, 3)) > SDead)?SDL_JoystickGetAxis(Controller, 3):0;
    
    Input_State[C_MOVEL] = (SDL_JoystickGetAxis(Controller, 0) <= -SThresh)?1:0;
    Input_State[C_MOVER] = (SDL_JoystickGetAxis(Controller, 0) >=  SThresh)?1:0;
    Input_State[C_MOVEU] = (SDL_JoystickGetAxis(Controller, 1) <= -SThresh)?1:0;
    Input_State[C_MOVED] = (SDL_JoystickGetAxis(Controller, 1) >=  SThresh)?1:0;
    
    Input_State[C_LOOKL] = (SDL_JoystickGetAxis(Controller, 2) <= -SThresh)?1:0;
    Input_State[C_LOOKR] = (SDL_JoystickGetAxis(Controller, 2) >=  SThresh)?1:0;
    Input_State[C_LOOKU] = (SDL_JoystickGetAxis(Controller, 3) <= -SThresh)?1:0;
    Input_State[C_LOOKD] = (SDL_JoystickGetAxis(Controller, 3) >=  SThresh)?1:0;
    
    Input_State[C_A]     = SDL_JoystickGetButton(Controller, 14);
    Input_State[C_B]     = SDL_JoystickGetButton(Controller, 13);
    Input_State[C_X]     = SDL_JoystickGetButton(Controller, 15);
    Input_State[C_Y]     = SDL_JoystickGetButton(Controller, 12);
    Input_State[C_LB]    = SDL_JoystickGetButton(Controller, 10);
    Input_State[C_RB]    = SDL_JoystickGetButton(Controller, 11);
    Input_State[C_LT]    = SDL_JoystickGetButton(Controller, 8);
    Input_State[C_RT]    = SDL_JoystickGetButton(Controller, 9);
    Input_State[C_LS]    = SDL_JoystickGetButton(Controller, 1);
    Input_State[C_RS]    = SDL_JoystickGetButton(Controller, 2);
    Input_State[C_U]     = SDL_JoystickGetButton(Controller, 4);
    Input_State[C_R]     = SDL_JoystickGetButton(Controller, 5);
    Input_State[C_D]     = SDL_JoystickGetButton(Controller, 6);
    Input_State[C_L]     = SDL_JoystickGetButton(Controller, 7);
    Input_State[C_BACK]  = SDL_JoystickGetButton(Controller, 0);
    Input_State[C_START] = SDL_JoystickGetButton(Controller, 3);
    Input_State[C_GUIDE] = SDL_JoystickGetButton(Controller, 16);
    
  }
  if ( name == "Sony Computer Entertainment Wireless Controller" )
  {
    Input_State[C_MOVEX] = (abs(SDL_JoystickGetAxis(Controller, 0)) > SDead)?SDL_JoystickGetAxis(Controller, 0):0;
    Input_State[C_MOVEY] = (abs(SDL_JoystickGetAxis(Controller, 1)) > SDead)?SDL_JoystickGetAxis(Controller, 1):0;
    Input_State[C_LOOKX] = (abs(SDL_JoystickGetAxis(Controller, 2)) > SDead)?SDL_JoystickGetAxis(Controller, 2):0;
    Input_State[C_LOOKY] = (abs(SDL_JoystickGetAxis(Controller, 5)) > SDead)?SDL_JoystickGetAxis(Controller, 3):0;
    
    Input_State[C_MOVEL] = (SDL_JoystickGetAxis(Controller, 0) <= -SThresh)?1:0;
    Input_State[C_MOVER] = (SDL_JoystickGetAxis(Controller, 0) >=  SThresh)?1:0;
    Input_State[C_MOVEU] = (SDL_JoystickGetAxis(Controller, 1) <= -SThresh)?1:0;
    Input_State[C_MOVED] = (SDL_JoystickGetAxis(Controller, 1) >=  SThresh)?1:0;
    
    Input_State[C_LOOKL] = (SDL_JoystickGetAxis(Controller, 2) <= -SThresh)?1:0;
    Input_State[C_LOOKR] = (SDL_JoystickGetAxis(Controller, 2) >=  SThresh)?1:0;
    Input_State[C_LOOKU] = (SDL_JoystickGetAxis(Controller, 5) <= -SThresh)?1:0;
    Input_State[C_LOOKD] = (SDL_JoystickGetAxis(Controller, 5) >=  SThresh)?1:0;
    
    Input_State[C_A]     = SDL_JoystickGetButton(Controller, 1);
    Input_State[C_B]     = SDL_JoystickGetButton(Controller, 2);
    Input_State[C_X]     = SDL_JoystickGetButton(Controller, 0);
    Input_State[C_Y]     = SDL_JoystickGetButton(Controller, 3);
    Input_State[C_LB]    = SDL_JoystickGetButton(Controller, 4);
    Input_State[C_RB]    = SDL_JoystickGetButton(Controller, 5);
    Input_State[C_LT]    = SDL_JoystickGetButton(Controller, 6);
    Input_State[C_RT]    = SDL_JoystickGetButton(Controller, 7);
    Input_State[C_LS]    = SDL_JoystickGetButton(Controller, 10);
    Input_State[C_RS]    = SDL_JoystickGetButton(Controller, 11);
    Input_State[C_U]     = (SDL_JoystickGetHat(Controller, 0) & SDL_HAT_UP)?1:0;
    Input_State[C_R]     = (SDL_JoystickGetHat(Controller, 0) & SDL_HAT_RIGHT)?1:0;
    Input_State[C_D]     = (SDL_JoystickGetHat(Controller, 0) & SDL_HAT_DOWN)?1:0;
    Input_State[C_L]     = (SDL_JoystickGetHat(Controller, 0) & SDL_HAT_LEFT)?1:0;
    Input_State[C_BACK]  = SDL_JoystickGetButton(Controller, 8);
    Input_State[C_START] = SDL_JoystickGetButton(Controller, 9);
    Input_State[C_GUIDE] = SDL_JoystickGetButton(Controller, 12);
    Input_State[C_BIGASS]= SDL_JoystickGetButton(Controller, 13);
    
  }
  if ( name == "Microsoft X-Box 360 pad" )
  {
    Input_State[C_MOVEX] = (abs(SDL_JoystickGetAxis(Controller, 0)) >= SDead)?SDL_JoystickGetAxis(Controller, 0):0;
    Input_State[C_MOVEY] = (abs(SDL_JoystickGetAxis(Controller, 1)) >= SDead)?SDL_JoystickGetAxis(Controller, 1):0;
    Input_State[C_LOOKX] = (abs(SDL_JoystickGetAxis(Controller, 3)) >= SDead)?SDL_JoystickGetAxis(Controller, 3):0;
    Input_State[C_LOOKY] = (abs(SDL_JoystickGetAxis(Controller, 4)) >= SDead)?SDL_JoystickGetAxis(Controller, 4):0;
    
    Input_State[C_MOVEL] = (SDL_JoystickGetAxis(Controller, 0) <= -SThresh)?1:0;
    Input_State[C_MOVER] = (SDL_JoystickGetAxis(Controller, 0) >=  SThresh)?1:0;
    Input_State[C_MOVEU] = (SDL_JoystickGetAxis(Controller, 1) <= -SThresh)?1:0;
    Input_State[C_MOVED] = (SDL_JoystickGetAxis(Controller, 1) >=  SThresh)?1:0;
    
    Input_State[C_LOOKL] = (SDL_JoystickGetAxis(Controller, 3) <= -SThresh)?1:0;
    Input_State[C_LOOKR] = (SDL_JoystickGetAxis(Controller, 3) >=  SThresh)?1:0;
    Input_State[C_LOOKU] = (SDL_JoystickGetAxis(Controller, 4) <= -SThresh)?1:0;
    Input_State[C_LOOKD] = (SDL_JoystickGetAxis(Controller, 4) >=  SThresh)?1:0;
    
    Input_State[C_A]     = SDL_JoystickGetButton(Controller, 0);
    Input_State[C_B]     = SDL_JoystickGetButton(Controller, 1);
    Input_State[C_X]     = SDL_JoystickGetButton(Controller, 2);
    Input_State[C_Y]     = SDL_JoystickGetButton(Controller, 3);
    Input_State[C_LB]    = SDL_JoystickGetButton(Controller, 4);
    Input_State[C_RB]    = SDL_JoystickGetButton(Controller, 5);
    Input_State[C_LT]    = (SDL_JoystickGetAxis(Controller, 2) >= TThresh)?1:0;
    Input_State[C_RT]    = (SDL_JoystickGetAxis(Controller, 5) >= TThresh)?1:0;
    Input_State[C_LS]    = SDL_JoystickGetButton(Controller, 9);
    Input_State[C_RS]    = SDL_JoystickGetButton(Controller, 10);
    Input_State[C_U]     = (SDL_JoystickGetHat(Controller, 0) & SDL_HAT_UP)?1:0;
    Input_State[C_R]     = (SDL_JoystickGetHat(Controller, 0) & SDL_HAT_RIGHT)?1:0;
    Input_State[C_D]     = (SDL_JoystickGetHat(Controller, 0) & SDL_HAT_DOWN)?1:0;
    Input_State[C_L]     = (SDL_JoystickGetHat(Controller, 0) & SDL_HAT_LEFT)?1:0;
    Input_State[C_BACK]  = SDL_JoystickGetButton(Controller, 6);
    Input_State[C_START] = SDL_JoystickGetButton(Controller, 7);
    Input_State[C_GUIDE] = SDL_JoystickGetButton(Controller, 8);
  }
}

Input_Enum Parse_Input_Event(SDL_Event* event, int* quit)
{
  std::string name = "";
  switch (event->type)
  {
    case SDL_KEYDOWN:
      Input_Set_Keyboard_State ((Input_Enum)(event->key.keysym.scancode), 1);
      return Input_Event((Input_Enum)(event->key.keysym.scancode));
    case SDL_KEYUP:
      Input_Set_Keyboard_State ((Input_Enum)(event->key.keysym.scancode), 0); return UNKNOWN;
      
    case SDL_JOYBUTTONDOWN: name = SDL_JoystickNameForIndex (event->jbutton.which); Input_Set_Controller_State(); break;
    case SDL_JOYBUTTONUP:   name = SDL_JoystickNameForIndex (event->jbutton.which); Input_Set_Controller_State(); break;
    case SDL_JOYAXISMOTION: name = SDL_JoystickNameForIndex (event->jaxis.which);   Input_Set_Controller_State(); break;
    case SDL_JOYHATMOTION:  name = SDL_JoystickNameForIndex (event->jhat.which);    Input_Set_Controller_State(); break;
    case SDL_JOYDEVICEADDED: if (event->jdevice.which == 0 ) Controller = SDL_JoystickOpen (event->jdevice.which); std::cout << "Controller Added\n"; break;
    case SDL_JOYDEVICEREMOVED: if (event->jdevice.which == 0) SDL_JoystickClose(Controller); std::cout << "Controller Removed\n"; break;
    default: return UNKNOWN;;
  }

  if ( name == "Sony PLAYSTATION(R)3 Controller" )
  {
    switch (event->type)
    {
      case SDL_JOYBUTTONDOWN:
        switch (event->jbutton.button)
        {
          case 0:  return Input_Event(C_BACK);
          case 1:  return Input_Event(C_LS);
          case 2:  return Input_Event(C_RS);
          case 3:  return Input_Event(C_START);
          case 4:  return Input_Event(C_U);
          case 5:  return Input_Event(C_R);
          case 6:  return Input_Event(C_D);
          case 7:  return Input_Event(C_L);
          case 8:  return Input_Event(C_LT);
          case 9:  return Input_Event(C_RT);
          case 10: return Input_Event(C_LB);
          case 11: return Input_Event(C_RB);
          case 12: return Input_Event(C_Y);
          case 13: return Input_Event(C_B);
          case 14: return Input_Event(C_A);
          case 15: return Input_Event(C_X);
          case 16: return Input_Event(C_GUIDE);
        }
        break;
      case SDL_JOYAXISMOTION:
        switch (event->jaxis.axis)
        {
          case 0:
            if (( LastLAX < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastLAX = event->jaxis.value;
              return Input_Event(C_MOVER);
            }
            if (( LastLAX > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastLAX = event->jaxis.value;
              return Input_Event(C_MOVEL);
            }
            LastLAX = event->jaxis.value;
            break;
          case 1:
            if (( LastLAY < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastLAY = event->jaxis.value;
              return Input_Event(C_MOVED);
            }
            if (( LastLAY > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastLAY = event->jaxis.value;
              return Input_Event(C_MOVEU);
            }
            LastLAY = event->jaxis.value;
            break;
          case 2:
            if (( LastRAX < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastRAX = event->jaxis.value;
              return Input_Event(C_LOOKR);
            }
            if (( LastRAX > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastRAX = event->jaxis.value;
              return Input_Event(C_LOOKL);
            }
            LastRAX = event->jaxis.value;
            break;
          case 3:
            if (( LastRAY < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastRAY = event->jaxis.value;
              return Input_Event(C_LOOKD);
            }
            if (( LastRAY > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastRAY = event->jaxis.value;
              return Input_Event(C_LOOKU);
            }
            LastRAY = event->jaxis.value;
            break;
            /*
          case 4:
            if ( ( LastRAT < TThresh ) && ( event->jaxis.value >= TThresh ) )
            {
              LastRAT = event->jaxis.value;
              return Input_Event(C_RT);
            }
            LastRAT = event->jaxis.value;
            break; */
        }
        break;
      default: return UNKNOWN;
    }
  }
  if ( name == "Sony Computer Entertainment Wireless Controller" )
  {
    switch (event->type)
    {
      case SDL_JOYBUTTONDOWN:
        switch (event->jbutton.button)
        {
          case 0:  return Input_Event(C_X);
          case 1:  return Input_Event(C_A);
          case 2:  return Input_Event(C_B);
          case 3:  return Input_Event(C_Y);
          case 4:  return Input_Event(C_LB);
          case 5:  return Input_Event(C_RB);
          case 6:  return Input_Event(C_LT);
          case 7:  return Input_Event(C_RT);
          case 8:  return Input_Event(C_BACK);
          case 9:  return Input_Event(C_START);
          case 10: return Input_Event(C_LS);
          case 11: return Input_Event(C_RS);
          case 12: return Input_Event(C_GUIDE);
          case 13: return Input_Event(C_BIGASS);
        }
        break;
      case SDL_JOYAXISMOTION:
        switch (event->jaxis.axis)
        {
          case 0:
            if (( LastLAX < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastLAX = event->jaxis.value;
              return Input_Event(C_MOVER);
            }
            if (( LastLAX > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastLAX = event->jaxis.value;
              return Input_Event(C_MOVEL);
            }
            LastLAX = event->jaxis.value;
            break;
          case 1:
            if (( LastLAY < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastLAY = event->jaxis.value;
              return Input_Event(C_MOVED);
            }
            if (( LastLAY > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastLAY = event->jaxis.value;
              return Input_Event(C_MOVEU);
            }
            LastLAY = event->jaxis.value;
            break;
          case 2:
            if (( LastRAX < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastRAX = event->jaxis.value;
              return Input_Event(C_LOOKR);
            }
            if (( LastRAX > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastRAX = event->jaxis.value;
              return Input_Event(C_LOOKL);
            }
            LastRAX = event->jaxis.value;
            break;
          case 5:
            if (( LastRAY < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastRAY = event->jaxis.value;
              return Input_Event(C_LOOKD);
            }
            if (( LastRAY > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastRAY = event->jaxis.value;
              return Input_Event(C_LOOKU);
            }
            LastRAY = event->jaxis.value;
            break;
        }
        break;
      case SDL_JOYHATMOTION:
        if ( event->jhat.value == SDL_HAT_UP )        return Input_Event(C_U);
        if ( event->jhat.value == SDL_HAT_RIGHT )     return Input_Event(C_R);
        if ( event->jhat.value == SDL_HAT_DOWN )      return Input_Event(C_D);
        if ( event->jhat.value == SDL_HAT_LEFT )      return Input_Event(C_L);
        break;
      default: return UNKNOWN;
    }
  }
  if ( name == "Microsoft X-Box 360 pad" )
  {
    switch (event->type)
    {
      case SDL_JOYBUTTONDOWN:
        switch (event->jbutton.button)
        {
          case 0:  return Input_Event(C_A);
          case 1:  return Input_Event(C_B);
          case 2:  return Input_Event(C_X);
          case 3:  return Input_Event(C_Y);
          case 4:  return Input_Event(C_LB);
          case 5:  return Input_Event(C_RB);
          case 6:  return Input_Event(C_BACK);
          case 7:  return Input_Event(C_START);
          case 8:  return Input_Event(C_GUIDE);
          case 9:  return Input_Event(C_LS);
          case 10: return Input_Event(C_RS);
        }
        break;
      case SDL_JOYAXISMOTION:
        switch (event->jaxis.axis)
        {
          case 0:
            if (( LastLAX < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastLAX = event->jaxis.value;
              return Input_Event(C_MOVER);
            }
            if (( LastLAX > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastLAX = event->jaxis.value;
              return Input_Event(C_MOVEL);
            }
            LastLAX = event->jaxis.value;
            break;
          case 1:
            if (( LastLAY < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastLAY = event->jaxis.value;
              return Input_Event(C_MOVED);
            }
            if (( LastLAY > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastLAY = event->jaxis.value;
              return Input_Event(C_MOVEU);
            }
            LastLAY = event->jaxis.value;
            break;
          case 2:
            if (( LastLAT < TThresh ) && ( event->jaxis.value >= TThresh ))
            {
              LastLAT = event->jaxis.value;
              return Input_Event(C_LT);
            }
            LastLAT = event->jaxis.value;
            break;
          case 3:
            if (( LastRAX < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastRAX = event->jaxis.value;
              return Input_Event(C_LOOKR);
            }
            if (( LastRAX > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastRAX = event->jaxis.value;
              return Input_Event(C_LOOKL);
            }
            LastRAX = event->jaxis.value;
            break;
          case 4:
            if (( LastRAY < SThresh ) && ( event->jaxis.value >= SThresh ))
            {
              LastRAY = event->jaxis.value;
              return Input_Event(C_LOOKD);
            }
            if (( LastRAY > -SThresh ) && ( event->jaxis.value <= -SThresh ))
            {
              LastRAY = event->jaxis.value;
              return Input_Event(C_LOOKU);
            }
            LastRAY = event->jaxis.value;
            break;
          case 5:
            if ( ( LastRAT < TThresh ) && ( event->jaxis.value >= TThresh ) )
            {
              LastRAT = event->jaxis.value;
              return Input_Event(C_RT);
            }
            LastRAT = event->jaxis.value;
            break;
        }
        break;
      case SDL_JOYHATMOTION:
        if ( event->jhat.value == SDL_HAT_UP )        return Input_Event(C_U);
        if ( event->jhat.value == SDL_HAT_RIGHT )     return Input_Event(C_R);
        if ( event->jhat.value == SDL_HAT_DOWN )      return Input_Event(C_D);
        if ( event->jhat.value == SDL_HAT_LEFT )      return Input_Event(C_L);
        break;
      default: return UNKNOWN;
    }
  }
  return UNKNOWN;
}

#endif
