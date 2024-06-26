#include "hist_model.hpp"

namespace hist::model {
    HistModel::HistModel() noexcept
        : _maxTopWords{ 15 },
          _allReadedWords{ 0 },
          _readedBytes{ 0 }
    {}

    QUrl HistModel::getSelectedFilePath() const noexcept {
        return _file.path;
    }

    void HistModel::setSelectedFilePath(QUrl path) noexcept {
        if (_file.path == path)
            return;
        _file.path = std::move(path);
    }

    qint64 HistModel::getSelectedFileSize() const noexcept {
        return _file.size;
    }

    void HistModel::setSelectedFileSize(qint64 size) noexcept {
        if (_file.size == size)
            return;
        _file.size = size;
    }

    int HistModel::getMaxTopWords() const noexcept {
        return _maxTopWords;
    }

    size_t &HistModel::getAllReadedWords() noexcept {
        return _allReadedWords;
    }

    qint64 &HistModel::readedBytes() noexcept {
        return _readedBytes;
    }

    structures::WordsStatistics& HistModel::getStatistics() noexcept {
        return _statistics;
    }

    structures::WordsStatistics::topWords_t& HistModel::getCurrentTop() noexcept {
        return _currentTop;
    }
}
