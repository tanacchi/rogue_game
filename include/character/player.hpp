#ifndef INCLUDED_PLAYER_HPP
#define INCLUDED_PLAYER_HPP

#include <list>
#include <map>
#include <memory>
#include <vector>

#include <character/character.hpp>
#include <item/item.hpp>
#include <keyboard/key_manager.hpp>

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
        void store(::ItemPtr&& item);
        void use(Player* const player_ptr, std::size_t item_index);
        std::list<::ItemPtr> items_;
      private:
        std::size_t capacity_;
    };

    Player();

    // KeyState と移動方向の対応表
    static const std::map<KeyManager::KeyType, const Point<int>> motion_table;

    // money の getter と setter
    // ステータスごとに２個ずつメソッドが増えることは避けたい
    std::size_t get_money() const;
    void add_money(std::size_t addition);
    void store_item(::ItemPtr&& item);
    void use_item(std::size_t item_index);
    std::vector<std::string> get_item_name_array() const;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    ::Point<int> get_direction() const;
    void assign_motion(const ::Point<int>& next_motion);

    Inventory inventory_;

  private:
    ::Point<int> direction_;
    std::size_t money_;
};

#endif  // INCLUDED_PLAYER_HPP
