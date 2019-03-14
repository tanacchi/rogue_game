#ifndef INCLUDED_PLAYER_HPP
#define INCLUDED_PLAYER_HPP

#include <list>
#include <map>
#include <memory>
#include <vector>

#include <character/character.hpp>
#include <item/item.hpp>
#include <keyboard/key_manager.hpp>

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
      void store(::item::ItemPtr&& item);
      void use(Player* const player_ptr, std::size_t item_index);
    private:
      std::list<::item::ItemPtr> items_;
      std::size_t capacity_;
    };

    Player();
    
    // KeyState と移動方向の対応表
    static const std::map<KeyManager::KeyType, const map::Point<int>> motion_table;

    // money の getter と setter
    // ステータスごとに２個ずつメソッドが増えることは避けたい
    std::size_t get_money() const;
    void add_money(std::size_t addition);
    void store_item(::item::ItemPtr&& item);
    void use_item(std::size_t item_index);
    std::vector<std::string> get_item_name_array() const;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    ::map::Point<int> get_direction() const;
    void assign_motion(const ::map::Point<int>& next_motion);
  private:
    Inventory inventory_;
    ::map::Point<int> direction_;
    std::size_t money_;
  };
}

#endif  // INCLUDED_PLAYER_HPP
