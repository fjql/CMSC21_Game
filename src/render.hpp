#pragma once

#include <string>

inline std::string separator = "================================================================================";

inline std::string start =  " .------..------..------..------..------..------..------..------..------.       \n"
                            " |B.--. ||L.--. ||A.--. ||C.--. ||K.--. ||J.--. ||A.--. ||C.--. ||K.--. |.-.    \n"
                            " | :(): || :/\\: || (\\/) || :/\\: || :/\\: || :(): || (\\/) || :/\\: || :/\\: ((5))   \n"
                            " | ()() || (__) || :\\/: || :\\/: || :\\/: || ()() || :\\/: || :\\/: || :\\/: |'-.-.  \n"
                            " | '--'B|| '--'L|| '--'A|| '--'C|| '--'K|| '--'J|| '--'A|| '--'C|| '--'K| ((1)) \n"
                            " `------'`------'`------'`------'`------'`------'`------'`------'`------'  '-'  ";

inline std::string start_options = " 1.\tStart\n 2.\tExit";

inline std::string dealer = "\t\t ________\t ________\n"
                            "\t\t/ %s      \\\t/ ?      \\\n"
                            "\t\t|        |\t|        |\n"
                            "\t\t|        |\t|        |\n"
                            "\t\t|   %s    |\t|   ?    |\n"
                            "\t\t|        |\t|        |\n"
                            "\t\t|      %s |\t|      ? |\n"
                            "\t\t\\________/\t\\________/\n";

inline std::string player = "\t\t ________\t ________\n"
                            "\t\t/ %s      \\\t/ %s      \\\n"
                            "\t\t|        |\t|        |\n"
                            "\t\t|        |\t|        |\n"
                            "\t\t|   %s    |\t|   %s    |\n"
                            "\t\t|        |\t|        |\n"
                            "\t\t|      %s |\t|      %s |\n"
                            "\t\t\\________/\t\\________/\n";

inline std::string player_hit = "\t\t ________\t ________\t ________\n"
                                "\t\t/ %s      \\\t/ %s      \\\t/ %s      \\\n"
                                "\t\t|        |\t|        |\t|        |\n"
                                "\t\t|        |\t|        |\t|        |\n"
                                "\t\t|   %s    |\t|   %s    |\t|   %s    |\n"
                                "\t\t|        |\t|        |\t|        |\n"
                                "\t\t|      %s |\t|      %s |\t|      %s |\n"
                                "\t\t\\________/\t\\________/\t\\________/\n";

inline std::string player_hit2 =  "\t\t ________\t ________\t ________\t ________\n"
                                  "\t\t/ %s      \\\t/ %s      \\\t/ %s      \\\t/ %s      \\\n"
                                  "\t\t|        |\t|        |\t|        |\t|        |\n"
                                  "\t\t|        |\t|        |\t|        |\t|        |\n"
                                  "\t\t|   %s    |\t|   %s    |\t|   %s    |\t|   %s    |\n"
                                  "\t\t|        |\t|        |\t|        |\t|        |\n"
                                  "\t\t|      %s |\t|      %s |\t|      %s |\t|      %s |\n"
                                  "\t\t\\________/\t\\________/\t\\________/\t\\________/\n";

inline std::string bust = "";

inline std::string play_options = "1.\tHit\n2.\tStand\n3.\tReveal\n%s";