#include <string>

/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main
*/
#include <vector>
#include <tuple>

void parse(const std::string &csv)
{
    unsigned int nbr_line = 0;
    std::vector<std::tuple<std::string, std::vector<std::string>>> _array;

    for (int i = 0; csv[i]; i++)
        if (csv[i] == '\n')
            nbr_line++;
    unsigned long from = 0;
    for (unsigned int i = 0; i < nbr_line; i++) {
        std::string name = csv.substr(from, csv.find(',', from) - from);
        unsigned long end_line = csv.find('\n', from);
        from = csv.find(',', from) + 1;
        std::vector<std::string> value;

        while (from < end_line) {
            if (csv.find(',', from + 1) > end_line)
                value.push_back(csv.substr(from, csv.find('\n', from) - from));
            else
                value.push_back(csv.substr(from, csv.find(',', from) - from));
            from = csv.find(',', from + 1) + 1;
            if (from == 0)
                break;
            if (from > end_line)
                from = csv.find('\n', from);
        }
        from = end_line + 1;
        _array.push_back(std::tuple(name, value));
    }
    from = 0;
}

int main()
{
    parse("Interface,vmnet8,wlp58s0,lo,enp0s31f6,vmnet1\n"
          "Download,0,0,0,0,0\n"
          "Upload,0,0,0,0,0\n");
}
/*
int main()
{
    Application app;

    app.setup();
    app.run();
    return 0;
}
*/