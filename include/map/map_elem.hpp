#ifndef INCLUDED_MAP_ELEM_HPP
#define INCLUDED_MAP_ELEM_HPP

#include <string>

namespace map
{
  // マップ要素の基底クラス
  class MapElem {
  public:
    MapElem(std::string type);
    MapElem(MapElem&& rhs) noexcept;
    virtual ~MapElem() = default;

    // マップ要素の種類
    const std::string type;

    // マップ上での文字
    const char symbol;
  };

  // マップ要素の種類から文字を取得（初期化用）
  const char get_symbol(const std::string);
}

#endif  // INCLUDED_MAP_ELEM_HPP
