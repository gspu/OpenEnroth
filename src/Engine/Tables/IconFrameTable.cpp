#include "Engine/Tables/IconFrameTable.h"

#include "Engine/AssetsManager.h"

#include "Utility/String.h"

GraphicsImage *Icon::GetTexture() {
    if (!this->img) {
        this->img = assets->getImage_ColorKey(this->pTextureName);
    }

    return this->img;
}

Icon *IconFrameTable::GetIcon(unsigned int idx) {
    if (idx < pIcons.size()) return &this->pIcons[idx];
    return nullptr;
}

Icon *IconFrameTable::GetIcon(const char *pIconName) {
    for (unsigned int i = 0; i < pIcons.size(); i++) {
        if (iequals(pIconName, this->pIcons[i].GetAnimationName()))
            return &this->pIcons[i];
    }
    return nullptr;
}

//----- (00494F3A) --------------------------------------------------------
unsigned int IconFrameTable::FindIcon(const std::string &pIconName) {
    for (size_t i = 0; i < pIcons.size(); i++) {
        if (iequals(pIconName, this->pIcons[i].GetAnimationName()))
            return i;
    }
    return 0;
}

//----- (00494F70) --------------------------------------------------------
Icon *IconFrameTable::GetFrame(unsigned int uIconID, Duration frame_time) {
    //    int v6; // edx@3
    int i;

    if (this->pIcons[uIconID].uFlags & 1 && this->pIcons[uIconID].GetAnimLength()) {
        Duration t = frame_time;

        t = (t /*/ 8*/) %
            this->pIcons[uIconID].GetAnimLength();

        // TODO(captainurist): #time get rid of yet another way to count time. / 8 should go.
        int tt = t.ticks() / 8;
        for (i = uIconID; tt >= this->pIcons[i].GetAnimTime(); i++)
            tt -= this->pIcons[i].GetAnimTime();
        return &this->pIcons[i];
    } else {
        return &this->pIcons[uIconID];
    }
}

//----- (00494FBF) --------------------------------------------------------
void IconFrameTable::InitializeAnimation(unsigned int uIconID) {
    if (uIconID && uIconID <= pIcons.size()) {
        for (int i = uIconID;; ++i) {
            if (!(this->pIcons[i].uFlags & 1)) {
                break;
            }
        }
    }
}
