#pragma once
/*
 *      Copyright (C) 2012-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include <map>
#include "ThumbLoader.h"

class CFileItem;
class CMusicDatabase;
class EmbeddedArt;

class CMusicThumbLoader : public CThumbLoader
{
public:
  CMusicThumbLoader();
  ~CMusicThumbLoader() override;

  void OnLoaderStart() override;
  void OnLoaderFinish() override;

  bool LoadItem(CFileItem* pItem) override;
  bool LoadItemCached(CFileItem* pItem) override;
  bool LoadItemLookup(CFileItem* pItem) override;

  /*! \brief helper function to fill the art for a video library item
   \param item a video CFileItem
   \return true if we fill art, false otherwise
   */
  bool FillLibraryArt(CFileItem &item) override;
  
  /*! \brief Fill the thumb of a music file/folder item
   First uses a cached thumb from a previous run, then checks for a local thumb
   and caches it for the next run
   \param item the CFileItem object to fill
   \return true if we fill the thumb, false otherwise
   */
  virtual bool FillThumb(CFileItem &item, bool folderThumbs = true);
  
  static bool GetEmbeddedThumb(const std::string &path, EmbeddedArt &art);

protected:
  CMusicDatabase *m_musicDatabase;
  typedef std::map<int, std::map<std::string, std::string> > ArtCache;
  ArtCache m_albumArt;
};
