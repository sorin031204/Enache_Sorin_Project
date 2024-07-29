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

    collection->addNote(*note1);
    EXPECT_EQ(collection->getSize(), 1);

    collection->addNote(*note2);
    EXPECT_EQ(collection->getSize(), 2);

    collection->addNote(*note3);
    EXPECT_EQ(collection->getSize(), 2);

    collection->removeNote(*note1);
    EXPECT_EQ(collection->getSize(), 1);

    note2->lockNote();
    collection->removeNote(*note2);
    EXPECT_EQ(collection->getSize(), 1);
}
TEST(CollectionTest, UpdateNote) {
    auto *collection = new Collection("TestCollection", 2);
    Note *note1 = new Note("Title1", "Text1");
    Note *note2 = new Note("Title2", "Text2");
    collection->addNote(*note1);
    EXPECT_EQ(collection->getSize(), 1);

    collection->updateNote("Title1", "NewTitle1", "NewText1");
    auto it = std::find_if(collection->getNotes().begin(), collection->getNotes().end(),
                           [](const Note &n) { return n.getTitle() == "NewTitle1"; });

    collection->updateNote("Title2", "NewTitle2", "NewText2");
    auto it2 = std::find_if(collection->getNotes().begin(), collection->getNotes().end(),
                           [](const Note &n) { return n.getTitle() == "NewTitle2"; });

    EXPECT_EQ(it->getTitle(), "NewTitle1");
    EXPECT_EQ(it->getText(), "NewText1");

    EXPECT_EQ(it2->getTitle(), "");
    EXPECT_EQ(it2->getText(), "");
}
