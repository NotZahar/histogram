#pragma once

#include <QUrl>

namespace hist::model {
    class HistModel final {
        struct SelectedFile {
            QUrl path;
            qint64 size;
        };

    public:
        HistModel() = default;

        ~HistModel() = default;

        QUrl getSelectedFilePath() const noexcept;
        void setSelectedFilePath(QUrl path) noexcept;

        qint64 getSelectedFileSize() const noexcept;
        void setSelectedFileSize(qint64 size) noexcept;

    private:
        SelectedFile _file;
    };
}
