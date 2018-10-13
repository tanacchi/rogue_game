#ifndef INCLUDED_TEXT_MAP_HPP
#define INCLUDED_TEXT_MAP_HPP

#include <iostream>

namespace map
{
  namespace generator
  {
    // テキストファイルから直接読み込むマップの情報
    // MapGenerator のフレンド関数でもいいかもしれない
    struct TextMap {
    public:
      // テキストファイルからマップの情報を抽出しインスタンスを生成
      TextMap(const std::vector<std::string>& map_strings);
      std::size_t width{};      // TODO : const 化
      std::size_t height{};
      std::string text{};

      void show() const;
    private:
      const std::size_t get_width(const std::vector<std::string>& map_strings);
      const std::size_t get_height(const std::vector<std::string>& map_strings);
      const std::string get_text(const std::vector<std::string>& map_strings);
    };

    const std::vector<std::string> read_map_strings(const std::string& filename); // TODO : 不要になったので削除
  }
}

#endif  // INCLUDED_TEXT_MAP_HPP
