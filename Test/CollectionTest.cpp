//
// Created by Sorin Andrei Enache on 14/07/24.
//

#include "../Collection.h"
#include "gtest/gtest.h"

TEST(CollectionTest, AddAndRemoveNote) {
    auto *collection = new Collection("TestCollection", 2);

    Note *note1 = new Note("Title1", "Text1");
    Note *note2 = new Note("Title2", "Text2");
    Note *note3 = new Note("Title3", "Text3");


    collection->AddNote(*note1);
    EXPECT_EQ(collection->getSize(), 1);


    collection->AddNote(*note2);
    EXPECT_EQ(collection->getSize(), 2);


    collection->AddNote(*note3);
    EXPECT_EQ(collection->getSize(), 2);


    collection->RemoveNote(*note1);
    EXPECT_EQ(collection->getSize(), 1);


    note2->LockNote();
    collection->RemoveNote(*note2);
    EXPECT_EQ(collection->getSize(), 1);
}

