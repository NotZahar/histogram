#include <map>
#include <unordered_map>
#include <unordered_set>

#include <QDebug> // TODO:
#include <QString>
#include <QUrl>

namespace hist::structures {
    struct SelectedFile {
        QUrl path;
        qint64 size;
    };

    class WordsStatistics {
        using quantity_t = int;
        using position_t = int;

        struct WordData {
            quantity_t quantity;
            position_t position;
        };

        struct ResultWordData {
            QString word;
            quantity_t quantity;
        };

    public:
        using topWords_t = std::map<position_t, ResultWordData>;

        WordsStatistics() noexcept = default;

        ~WordsStatistics() = default;

        topWords_t getTopNWords(const int N) const noexcept {
            topWords_t result;
            for (int i = 0; const auto& topWord : _wordsTop) {
                if (i >= N)
                    break;
                const QString& word = topWord.second;
                assert(_words.contains(word));
                const auto& data = _words.at(word);
                assert(i == data.position);
                ResultWordData resultData{ word, data.quantity };
                result.insert({ data.position, resultData });
                ++i;
            }

            return result;
        }

        void addWord(QString word) noexcept {
            assert(_words.size() == _wordsTop.size());

            if (_words.contains(word)) {
                WordData& data = _words.at(word);
                data.quantity += 1;
                updatePosition(word);
                return;
            }

            const int currentNumberOfWords = _words.size();
            WordData newWordData{ 1, currentNumberOfWords };
            _words.insert({ word, newWordData });
            _wordsTop.insert({ currentNumberOfWords, word });
        }

    private:
        void updatePosition(const QString& word) {
            assert(_words.contains(word));
            WordData& currentData = _words.at(word);
            const position_t currentPosition = currentData.position;
            const quantity_t currentQuantity = currentData.quantity;

            if (currentPosition == 0)
                return;

            assert(_wordsTop.contains(currentPosition - 1));
            const QString& previousWord = _wordsTop.at(currentPosition - 1);

            assert(_words.contains(previousWord));
            WordData& previousData = _words.at(previousWord);
            const quantity_t previousQuantity = previousData.quantity;

            if (currentQuantity <= previousQuantity)
                return;

            currentData.position -= 1;
            previousData.position += 1;

            assert(currentData.position >= 0);
            assert(_wordsTop.contains(currentData.position));
            assert(_wordsTop.contains(previousData.position));
            std::swap(_wordsTop.at(currentData.position), _wordsTop.at(previousData.position));

            if (currentData.position == 0)
                return;

            assert(_wordsTop.contains(currentData.position - 1));
            const QString& candidateWord = _wordsTop.at(currentData.position - 1);

            assert(_words.contains(candidateWord));
            const WordData& candidateData = _words.at(candidateWord);
            const quantity_t candidateQuantity = candidateData.quantity;
            if (currentQuantity > candidateQuantity)
                updatePosition(word);
        }

        std::unordered_map<QString, WordData> _words;
        std::map<position_t, QString> _wordsTop;
    };
}
