//
// Created by Sorin Andrei Enache on 12/07/24.
//
#include "gtest/gtest.h"

#include "../Note.h"


TEST(NoteTest, CreateNote) {
    Note note("Test Title", "Test Text");
    EXPECT_EQ(note.getTitle(), "Test Title");
    EXPECT_EQ(note.getText(), "Test Text");
    EXPECT_FALSE(note.isLocked());
    EXPECT_FALSE(note.isImportant());
}

TEST(NoteTest, ModifyNote) {
    Note note("Test Title", "Test Text");
    note.modifyTitle("New Title");
    note.modifyText("New Text");
    EXPECT_EQ(note.getTitle(), "New Title");
    EXPECT_EQ(note.getText(), "New Text");

    note.lockNote();
    note.modifyTitle("Another Title");
    note.modifyText("Another Text");
    EXPECT_EQ(note.getTitle(), "New Title");
    EXPECT_EQ(note.getText(), "New Text");

    note.unlockNote();
    note.modifyText("Another Text");
    note.modifyTitle("Another Title");
    EXPECT_EQ(note.getText(), "Another Text");
    EXPECT_EQ(note.getTitle(), "Another Title");
}
