#pragma once

#include <QUrl>

namespace hist::model {
    class HistModel final {
    public:
        HistModel() = default;

        ~HistModel() = default;

        QUrl getSelectedFilePath() const noexcept;
        void setSelectedFilePath(QUrl path) noexcept;

    private:
        QUrl _selectedFilePath;
    };
}
