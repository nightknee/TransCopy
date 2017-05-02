/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DiskObject.h
 * Author: karwan
 *
 * Created on 1 maja 2017, 22:59
 */

#ifndef DISKOBJECT_H
#define DISKOBJECT_H

#include <boost/filesystem.hpp>

class DiskObject : public boost::filesystem::path {
public:
    DiskObject();
    DiskObject(const DiskObject& orig);
    virtual ~DiskObject();
private:

};

#endif /* DISKOBJECT_H */

