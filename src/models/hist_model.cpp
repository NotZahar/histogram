#include "hist_model.hpp"

namespace hist::model {
    QUrl HistModel::getSelectedFilePath() const noexcept {
        return _selectedFilePath;
    }

    void HistModel::setSelectedFilePath(QUrl path) noexcept {
        if (_selectedFilePath == path)
            return;
        _selectedFilePath = std::move(path);
    }
}
