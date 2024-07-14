//
// Created by Sorin Andrei Enache on 12/07/24.
//
#include "gtest/gtest.h"

#include "../Note.h"


TEST(NoteTest, CreateNote) {
    Note note("Test Title", "Test Text");
    EXPECT_EQ(note.getTitle(), "Test Title");
    EXPECT_EQ(note.getText(), "Test Text");
    EXPECT_FALSE(note.StatusNote());
    EXPECT_FALSE(note.IsImportant());
}

TEST(NoteTest, ModifyNote) {
    Note note("Test Title", "Test Text");
    note.modifyTitle("New Title");
    note.modifyText("New Text");
    EXPECT_EQ(note.getTitle(), "New Title");
    EXPECT_EQ(note.getText(), "New Text");

    note.LockNote();
    note.modifyTitle("Another Title");
    note.modifyText("Another Text");
    EXPECT_EQ(note.getTitle(), "New Title");
    EXPECT_EQ(note.getText(), "New Text");

    note.UnLockNote();
    note.modifyText("Another Text");
    note.modifyTitle("Another Title");
    EXPECT_EQ(note.getText(), "Another Text");
    EXPECT_EQ(note.getTitle(), "Another Title");
}
