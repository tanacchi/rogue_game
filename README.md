# rogue_game
[![Build Status](https://travis-ci.org/tanacchi/rogue_game.png)](https://travis-ci.org/tanacchi/rogue_game)

version **0.4.0** in development.

[Wikipedia](https://ja.wikipedia.org/wiki/%E3%83%AD%E3%83%BC%E3%82%B0)


## Releases（リリース）
**[Latest（最新版）](https://github.com/tanacchi/rogue_game/releases/latest)**  
[Release List（リリース一覧）](https://github.com/tanacchi/rogue_game/releases)  


## How to build（ビルド方法）
`$ mkdir build ; cd build ;cmake .. ;make ;cd -`


## How to play（遊び方）
`$ ./rogue_game`

#### Dungeon mode（ダンジョンモード）
Key | Action
--- | ---
(Arrows（矢印キー）) | Move your character（キャラクター移動）
Space（スペース）| Open inventory（アイテム選択）

#### Inventory mode（アイテム選択モード）
Key | Action
--- | ---
(Arrows（矢印キー）) | Move cursor（カーソル移動）
Enter | Decide item（アイテム決定）
Space（スペース） | Exit inventory mode（アイテム選択モードを出る）
BackSpace | Exit inventory mode（アイテム選択モードを出る）


## Dependencies（依存パッケージ）
* ncurses
  > To install  
    `$ sudo apt install libncurses5-dev`
* libboost 1.65
  > To install  
    `$ sudo apt install libboost-all-dev`
