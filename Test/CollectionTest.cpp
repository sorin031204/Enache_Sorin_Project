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
    note2->lockNote();

    EXPECT_THROW(collection->addNote(*note3), std::runtime_error);

    collection->removeNote(*note1);
    EXPECT_EQ(collection->getSize(), 1);


    EXPECT_THROW(collection->removeNote(*note2), std::runtime_error);
    EXPECT_EQ(collection->getSize(), 1);

}
TEST(CollectionTest, UpdateNote) {
    Collection collection("Test Collection", 2);

    Note note1("Title1", "Text1");
    collection.addNote(note1);
    EXPECT_EQ(collection.getSize(), 1);

    EXPECT_TRUE(collection.updateNote("Title1", "NewTitle1", "NewText1"));
    auto it = std::find_if(collection.getNotes().begin(), collection.getNotes().end(), [](const Note& n) { return n.getTitle() == "NewTitle1"; });
    EXPECT_NE(it, collection.getNotes().end());
    EXPECT_EQ(it->getTitle(), "NewTitle1");
    EXPECT_EQ(it->getText(), "NewText1");

    note1.lockNote();
    EXPECT_THROW(collection.updateNote("NewTitle1", "AnotherTitle", "AnotherText"), std::runtime_error);

    EXPECT_EQ(it->getTitle(), "NewTitle1");
    EXPECT_EQ(it->getText(), "NewText1");


}
TEST(CollectionTest, UpdateNoteNonExistent){
    auto *collection = new Collection("TestCollection", 2);

    Note *note1 = new Note("Title1", "Text1");
    Note *note2 = new Note("Title2", "Text2");

    collection->addNote(*note1);
    collection->addNote(*note2);
    EXPECT_EQ(collection->getSize(), 2);

    EXPECT_THROW(collection->updateNote("Title3", "NewTitle3", "NewText3"), std::runtime_error);
}