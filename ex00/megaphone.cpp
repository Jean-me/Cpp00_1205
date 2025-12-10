#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++) // argv[0]はプログラム名なので1から開始
    {
        std::string str = argv[i];
        for (size_t j = 0; j < str.length(); j++) //C++styleヌル終端文字列の扱い（std::string を使用、str.length() で文字列の長さを取得
        {
            std::cout << static_cast<char>(std::toupper(argv[i][j]));//C++の推奨style:型変換が明示的、コード意図が明確に
        }
    }
    std::cout << std::endl;

    return 0;
}
