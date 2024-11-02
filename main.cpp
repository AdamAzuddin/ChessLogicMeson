#include "chess.hpp"
#include <vector>
#include <utility>

using namespace chess;

int uciSquareToBitboardIndex(const std::string &square)
{
    if (square.length() != 2)
        return -1;

    char file = square[0];
    char rank = square[1];

    int fileIndex = file - 'a';
    int rankIndex = rank - '1';

    return rankIndex * 8 + fileIndex;
}

std::pair<int, int> uciMoveToBitboardIndices(const std::string &uciMove)
{
    if (uciMove.length() != 4)
        return {-1, -1};

    std::string fromSquare = uciMove.substr(0, 2);
    std::string toSquare = uciMove.substr(2, 2);

    int fromIndex = uciSquareToBitboardIndex(fromSquare);
    int toIndex = uciSquareToBitboardIndex(toSquare);

    return {fromIndex, toIndex};
}

extern "C" {

    // Define a struct for a move with from and to indices
    struct MoveIndices {
        int from;
        int to;
    };

    // Expose this function to Unity
    __declspec(dllexport) const MoveIndices* getLegalMoves(const char* fen, int* moveCount) {
        static std::vector<MoveIndices> movesList; // Persistent storage

        chess::Board board(fen);
        chess::Movelist moves;
        chess::movegen::legalmoves(moves, board);

        // Clear previous moves and fill with new ones
        movesList.clear();
        for (const auto& move : moves) {
            auto indices = uciMoveToBitboardIndices(chess::uci::moveToUci(move));
            movesList.push_back({ indices.first, indices.second });
        }

        // Set moveCount for Unity to know the number of moves
        *moveCount = movesList.size();
        return movesList.data();  // Return a pointer to the array of moves
    }
}
