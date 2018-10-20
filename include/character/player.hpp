#ifndef INCLUDED_PLAYER_HPP
#define INCLUDED_PLAYER_HPP

#include <ostream>
#include <map>

#include <character/character.hpp>
#include <item/inventory.hpp>

namespace character
{
  class Player : public Character
  {
  public:
    Player(map::Point point);

    // KeyState と移動方向の対応表
    static const std::map<KeyboardManager::KeyState, const map::Point> motion_table;

    // money の getter と setter
    // ステータスごとに２個ずつメソッドが増えることは避けたい
    std::size_t get_money() const;
    void add_money(std::size_t addition);
    void store_item(std::unique_ptr<item::Item>&& item);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
  private:
    Inventory inventory_;
    std::size_t money_;
  };
}

#endif  // INCLUDED_PLAYER_HPP
