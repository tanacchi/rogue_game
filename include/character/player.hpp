#ifndef INCLUDED_PLAYER_HPP
#define INCLUDED_PLAYER_HPP

#include <ostream>
#include <map>
#include <memory>
#include <list>
#include <vector>

#include <character/character.hpp>
#include <item/item.hpp>

namespace character
{
  class Player : public Character
  {
  public:
    class Inventory
    {
    public:
      Inventory(std::size_t capacity);
      friend std::ostream& operator<<(std::ostream& os, const Inventory& inventory);
      std::size_t get_item_num() const;
      std::vector<std::string> get_item_name_array() const;
      void store(std::unique_ptr<item::Item>&& item);
      void use(Player* const player_ptr, std::size_t item_index);
    private:
      std::list<std::unique_ptr<item::Item> > items_;
      std::size_t capacity_;
    };

    Player();
    
    // KeyState と移動方向の対応表
    static const std::map<KeyboardManager::KeyState, const map::Point<int>> motion_table;

    // money の getter と setter
    // ステータスごとに２個ずつメソッドが増えることは避けたい
    std::size_t get_money() const;
    void add_money(std::size_t addition);
    void store_item(std::unique_ptr<item::Item>&& item);
    void use_item(std::size_t item_index);
    std::vector<std::string> get_item_name_array() const;
    std::string to_string() const;
  private:
    Inventory inventory_;
    std::size_t money_;
  };
}

#endif  // INCLUDED_PLAYER_HPP
