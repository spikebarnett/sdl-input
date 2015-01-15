#include "input.hpp"

int e1 = 0;
std::list<Input_Enum> Code_Konami1 = {C_U,C_U,C_D,C_D,C_L,C_R,C_L,C_R,C_B,C_A};
//std::list<Input_Enum> Code_Konami2 = {C_MOVEU,C_MOVEU,C_MOVED,C_MOVED,C_MOVEL,C_MOVER,C_MOVEL,C_MOVER,C_B,C_A};
//std::list<Input_Enum> Code_Konami3 = {K_UP,K_UP,K_DOWN,K_DOWN,K_LEFT,K_RIGHT,K_LEFT,K_RIGHT,K_B,K_A};
//std::list<Input_Enum> Code_Konami4 = {C_U,C_U,C_D,C_D,C_L,C_R,C_L,C_R,C_B,C_A,C_U,C_U,C_D,C_D,C_L,C_R,C_L,C_R,C_B,C_A};


int main(int argc, char* argv[])
{
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    
	//SDL_Window * window = 
	SDL_CreateWindow("SDL2 Joystick Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 256, 0, 0);
  //SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

  //SDL_Joystick *Controller = NULL;
  if( SDL_NumJoysticks() > 0 )
  {
    Controller = SDL_JoystickOpen( 0 );
  if( Controller == NULL )
  {
    std::cout << "Could not open joystick!\n";
  }
    std::cout << "Opened joystick!\n";
    std::cout << SDL_JoystickName(Controller) << "\n";
  } else {
    std::cout << "No joysticks found!\n";
  }
  


  // An SDL_Event struct
  SDL_Event event;
  //Controller_State *p1 = new Controller_State;

  // A bool to check if the program has exited
  int quit = 0;
  // While the program is running
  while(!quit)
  {
    // Check for new events
    //if SDL_PollEvent(&event);
    //SDL_WaitEvent(&event);
    while (SDL_PollEvent(&event))
    {
      //SDL_WaitEventTimeout(&event, 1);
      // If a quit event has been sent
      if (event.type == SDL_QUIT)
      {
        // Quit the application
        quit = 1;
      }
      e1 = Parse_Input_Event(&event, &quit);
    }
    /*
    for (int i = 283; i < 313; ++i)
    {
      std::cout << Input_Name((Input_Enum)i) << ":" << Input_State[i] << "\n";
    }
    std::cout << "\n";
    */
    //if (e1) std::cout << Input_Name((Input_Enum)e1) << "\n";
    
    Print_Input_Event_List();
    
    /*
    if ( Input_Event_List == Code_Konami1 ) std::cout << "Konami code entered!\n";
    if ( Input_Event_List == Code_Konami2 ) std::cout << "Konami code entered!\n";
    if ( Input_Event_List == Code_Konami3 ) std::cout << "Konami code entered!\n";
    */
    
    if (Input_Event_Check_Patern (Code_Konami1)) std::cout << "Konami code entered!\n";
    //if (Input_Event_Check_Patern (Code_Konami2)) std::cout << "Konami code entered!\n";
    //if (Input_Event_Check_Patern (Code_Konami3)) std::cout << "Konami code entered!\n";
    //if (Input_Event_Check_Patern (Code_Konami4)) std::cout << "Konami entered!\n";

    SDL_Delay(100);
  }

  SDL_Quit();
}
