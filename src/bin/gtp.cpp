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
#include <algorithm>
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
int getVertex(const char in) {
  char vertexes[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
  for (int i;i<9;i++) {
    if (vertexes[i] == in) {
      return i;
    }
  }
  return 0;
}
int main() {
  game *g = new game;
  bool running = true;
  
  while(running) {
    int id = 9999;
    char command[256];
    char arguments[256];
    int found = 0;
    // Scan stdin for input- either a ID+command combo, or just a command alone
    found = scanf(" %d %s", &id, command);
    if (found == 0) {
      found = scanf(" %s", command);
    }
    std::cout << "I got command " << command << " with id " << id << " and found " << found << endl;
    // Now we have our command - let's pick up the arguments.
    char arg[64];
    while(scanf(" %s ", arg) == 1) {
      strcat(arguments, arg);
      std::cout << "I got argument: " << arg << endl; 
    }
    std::cout << "I got arguments: " << arguments << " and found " << found << endl;
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
      // FIXME: Need to be able to handle arguments!
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