#pragma once

#include <QUrl>

#include "../utility/structures.hpp"

namespace hist::model {
    class HistModel final {
    public:
        HistModel() noexcept;

        ~HistModel() = default;

        QUrl getSelectedFilePath() const noexcept;
        void setSelectedFilePath(QUrl path) noexcept;

        qint64 getSelectedFileSize() const noexcept;
        void setSelectedFileSize(qint64 size) noexcept;

        int getMaxTopWords() const noexcept;
        size_t& getAllReadedWords() noexcept;
        qint64& readedBytes() noexcept;
        structures::WordsStatistics& getStatistics() noexcept;
        structures::WordsStatistics::topWords_t& getCurrentTop() noexcept;

    private:
        const int _maxTopWords;
        size_t _allReadedWords;
        qint64 _readedBytes;
        structures::WordsStatistics _statistics;
        structures::SelectedFile _file;
        structures::WordsStatistics::topWords_t _currentTop;
    };
}
