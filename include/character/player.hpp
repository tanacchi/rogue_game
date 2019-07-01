#ifndef INCLUDED_PLAYER_HPP
#define INCLUDED_PLAYER_HPP

#include <list>
#include <map>
#include <memory>
#include <vector>

#include <character/character.hpp>
#include <keyboard/key_manager.hpp>

class Inventory;
class PlayerDisplay;

class Player : public Character
{
  public:
    friend PlayerDisplay;  // XXX: Might not be beautiful

    Player();
    static const std::map<KeyManager::KeyType, const Point<int>> motion_table;
    std::size_t get_money() const;
    void add_money(std::size_t addition);
    Point<int> get_direction() const;
    void assign_motion(const Point<int>& next_motion);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    std::size_t get_max_hit_point() const noexcept;
    void heal(std::size_t amount) noexcept;

    std::shared_ptr<Inventory> inventory_ptr;

  private:
    Point<int> direction_;
    std::size_t max_hit_point_;
    std::size_t money_;
};

#endif  // INCLUDED_PLAYER_HPP
