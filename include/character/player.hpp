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
    Player();
    static const std::map<KeyManager::KeyType, const Point<int>> motion_table;
    std::size_t get_money() const;
    void add_money(std::size_t addition);
    void store_item(const ItemPtr& item);
    void dispose_item(std::size_t item_index);
    std::vector<std::string> get_item_name_array() const;
    Point<int> get_direction() const;
    void assign_motion(const Point<int>& next_motion);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    std::size_t get_max_hit_point() const noexcept;
    void toggle_hit_point(std::size_t amount);

  private:
    Point<int> direction_;
    std::size_t max_hit_point_;
    std::multimap<std::string, const ItemPtr> inventory_{};
    std::size_t money_;
};

#endif  // INCLUDED_PLAYER_HPP
