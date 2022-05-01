#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "SimpleData.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  const std::string fileName = "../leaderboard.txt";
  size_t playerID;

  CoreData readLB = SimpleData::ReadFile(fileName);
  LeaderBoard LeaderBoard(readLB.scoreMap, readLB.sortedScoreMap);
  LeaderBoard.displayBoard();
  // get player id here
  std::cout << "Please enter you player id here"<<std::endl;
  std::cin>>playerID;
  ScoreMap scoreMap = readLB.scoreMap;
  auto scoreRes = scoreMap.find(playerID);
  if (scoreRes == scoreMap.end()) {
      bool stopNow = true;
      while (stopNow) {
          playerID = GameUtil::get_uuid();
          if (scoreMap.find(playerID) == scoreMap.end()) {
              stopNow = false;
          }
      }
      std::cout<<"The player ID you entered does not exist. Here is your new player ID"<<playerID<<std::endl;
  }
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  //post-processing leaderboard
  LeaderBoard.addScore(playerID, game.GetScore());
  int status = std::remove(fileName.c_str());
  if(status==0)
      SimpleData::WriteFile(LeaderBoard.getCurScores(), LeaderBoard.getSortedScores(), fileName);
  else
      std::cerr<<"leaderboard.txt file might not exist at the first place!"; 

  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}