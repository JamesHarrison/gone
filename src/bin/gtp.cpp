/**
@file
@author James Harrison <james@talkunafraid.co.uk>

This program implements a simple implementation of the Go Text Protocol
(http://www.lysator.liu.se/~gunnar/gtp/gtp2-spec-draft2/gtp2-spec.html)
Version 2, minimum required command set.

This allows the Gone solver engine to be used to play against humans or
other engines via GTP and an arbitrator such as GoGUI.
*/
#include "game.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
using namespace gone;
/**
Outputs a GTP 'successful' response with the given response string and ID.

If the ID specified is 9999, the ID is omitted.
@param Character array to output as a response
@param Command ID for the response, which may be omitted (by using 9999) if it was omitted in the command
*/
void successResponse(const char* output, int id) {
  if (id != 9999) {
    std::cout << "="<< id << " " << output << "\n\n";
  } else {
    std::cout << "= "<< output << "\n\n";
  }
}
/**
Outputs a GTP 'failure' response with the given response string and ID.

If the ID specified is 9999, the ID is omitted.
@param Character array to output as a response
@param Command ID for the response, which may be omitted (by using 9999) if it was omitted in the command
*/
void failureResponse(const char* output, int id) {
  if (id != 9999) {
    std::cout << "?"<< id << " " << output << "\n\n";
  } else {
    std::cout << "? "<< output << "\n\n";
  }
}
int getVertex(const char* in) {
  char vertexes[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
  int x = 0;
  int y = 0;
  char * vtx;
  strcpy(vtx, in);
  char c;
  int i=0;
  while (vtx[i])
  {
    vtx[i] = tolower(vtx[i]);
    i++;
  }
  for (int i;i<9;i++) {
    if (vertexes[i] == vtx[0]) {
      x = i;
    }
  }
  y = atoi(vtx);
  return (x*y);
}
bool getColour(const char* in) {
  if (strcmp(in, "w") == 0 || strcmp(in, "white") == 0) {
    return true;
  }
  return false;
}
int main() {
  game *g = new game;
  bool running = true;
  
  while(running) {
    // Set our variables up.
    int id = 9999;
    char * command;
    char * arguments;
    // We're going to use readline to pull in the data we want from the cmdline.
    char *line = readline ("");
    // Now tokenize.
    char *pch = strtok(line, " ");
    // If the first token is an integer, that's our ID.
    if (atoi(pch) != 0) {
      id = atoi(pch);
      // Next, command
      pch = strtok (NULL, " ");
      command = pch;
    } else {
      // If it's not an integer, that's our command.
      command = pch;
    }
    pch = strtok (NULL, " ");
    arguments = new char[256];
    // The rest are arguments.
    while (pch != NULL)
    {
      strcat(arguments, pch);
      pch = strtok (NULL, " ");
      // Append a space if we've got another thing after this. Otherwise, no spaces.
      if (pch != NULL) {
        strcat(arguments, " ");
      }
    }
    // Debug output ahoy.
    std::cout << "I got command " << command << " with id " << id << " and arguments " << arguments << endl;
    if (strcmp(command,"protocol_version") == 0) {
      successResponse("2", id);
    } else if (strcmp(command,"name") == 0) {
      successResponse("Gone", id);
    } else if (strcmp(command,"version") == 0) {
      successResponse("0.4", id);
    } else if (strcmp(command,"known_command") == 0) {
      // FIXME: I need to be able to handle arguments!
      successResponse("false", id);
    } else if (strcmp(command,"list_commands") == 0) {
      successResponse("protocol_version\nname\nversion\nknown_command\nquit\nboardsize\nclear_board\nkomi\nplay\ngenmove", id);
    } else if (strcmp(command,"quit") == 0) {
      running = false;
      successResponse("", id); // We have to send a command prior to quitting
    } else if (strcmp(command,"boardsize") == 0) {
      if (atoi(arguments) != 9) {
        failureResponse("unacceptable size", id);
      } else {
        successResponse("", id);
      }
    } else if (strcmp(command,"clear_board") == 0) {
      delete g;
      g = new game;
      successResponse("", id);
    } else if (strcmp(command,"komi") == 0) {
      // TODO: Should probably actually do something with komi
      successResponse("", id); // We have to send a command prior to quitting
    } else if (strcmp(command,"play") == 0) {
      
    } else if (strcmp(command,"genmove") == 0) {
    } else {
      failureResponse("unknown command", id);
    }
  }
  delete g;
  return 0;
}