# Git Training

This repo houses ADC's git training lab, and consists of a simple example C++ library with unit tests.

First, clone the repo: `git clone https://github.com/tpyle/git-training.git`, then `cd git-training`.

Next, send Thomas (Teams: Thomas Pyle) your github ID, so he can grant you push access - you won't need it until Module 5, but it's worth getting out of the way early.

Get in a group with one of your neighbors! Most modules are done solo even within a group, but Modules 5, 8, and 9 need two people interacting with each other's branches. No neighbor (odd numbers, working remotely, etc.)? Each of those three modules has a "Working alone?" section showing how to simulate a partner with a second clone.

The structure of the lab is as follows:

## Module 1: Editing files (`git status`, `git add`, `git commit`)

The [mathlib.cpp](./src/mathlib.cpp) file has a few functions that are not currently implemented. Go ahead and implement one of them.

Afterwards, check your environment. Run `git status` to see your changes. Were any build artifacts included that need to be ignored?

Stage your changes with `git add ./src/mathlib.cpp`, and then commit them with `git commit -m "Adds support for <X>"`.

If you want, try breaking up your changes. `git add -p ./src/mathlib.cpp` will allow you to select the just the "hunks" (sub changes) in the file you want to stage, if you want to commit each function change individually while editing the file once.

## Module 2: Branching (`git branch`, `git switch`)

Wait a sec - we're editing on `main`! We should create a feature branch with our changes. Usually, the default branch is protected. If you try to push, you'll get an error!

Create a new branch with `git switch -c feature/<your name>-new-functions`. This would be standard practice for working on new code.

If you run `git status` now, you'll see you're now on branch `feature/<>-new-functions`.

Let's go cleanup `main` now - switch back to main with `git switch main` (note the lack of `-c`, this is because the branch doesn't need to be created).

Reset your branch to line up with the remote `main`. You can do this with `git fetch && git reset --hard origin/main` (Note: the `git fetch` is not a required feature, this makes your local main equal to whatever the remote it as that time, you can skip that to make your main the same as the last remote main you pulled).

With this complete, your local `main` now agrees with whatever the remote `main` and your local main changes are gone.

## Module 3: Merge Conflicts (`git merge`)

Let's introduce a merge conflict, so you can get used to it.

While on the `main` branch, fill in the same function you had completed in module 1. Put in something else, a comment, a different implementation, anything.

Stage those changed with `git add <path/to/file>` and commit that change with `git commit -m "My main only change"`.

Now, run `git merge feature/<your name>-new-functions`. This will merge in your feature branch into your local `main`, similar to what GitHub does when it processes a pull request. When this happens, git will tell you that there was merge conflict - this is because git can't identify how to resolve the differences from the two branches.

Git will say something like:

```
CONFLICT (content): Merge conflict in <file>
Automatic merge failed; fix conflicts and then commit the result.
```

This tells you that the merge failed. Run `git status` now - it will now include the following details:

```
You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)
        both modified:   <file path here>
```

This is git communicating to you the file(s) that are causing your merge conflict. Open that file. In it, you'll find a section like the following:

```
<<<<<<< HEAD
XXXXX
=======
YYYYY
>>>>>>> <your branch>
```

This is the "merge conflict", and there's potentially more than one. What it means, is that the `XXXXX` change was made on `HEAD` (in this case, `main`), and the `YYYYY` change was made on your branch, so you know where the change came from.

Manually edit the file to select the change that you want. The way you do that is by deleting the `<<<<<`, `>>>>>`, `=====` lines, and fixing the conflict.

Afterwards, stage the file with `git add <path/to/file>`.

Unlike a regular commit, git merges generate commit messages. If you just directly run `git commit`, it will open a window with the default commit message of `Merge branch '<your branch>'`,  go ahead and accept that commit message (just close the editor) or replace it with you own. You can also do `git commit -m "<Message>"` if desired.

Now that we've resolved our first merge conflict, let's go ahead and cleanup. Reset `main` back to the remote with `git fetch && git reset --hard origin/main`.

## Module 4: Git Stashes (`git stash`)

Switch back to your feature branch: `git switch feature/<your name>-new-functions`.

Pick another one of the not-yet-implemented functions and start on it, but stop partway through - don't commit yet.

Now say you need to jump over to `main` for a second (check something, help your neighbor, whatever) but you're not done here and don't want to commit half-finished code. Stash it: `git stash push -m "wip: <what you were doing>"`.

Run `git status` - clean, like the edit never happened. `git stash list` shows it's still there, saved for later.

Go switch to `main`, poke around, then come back (`git switch feature/<your name>-new-functions`) and run `git stash pop` to bring your changes back (this also removes them from the stash list). If you'd rather keep the stash around after restoring it - say, to apply it somewhere else too - use `git stash apply` instead.

Finish implementing the function, then `git add`/`git commit` it like you did in Module 1.

## Module 5: Remote Syncing (`git pull`, `git push`)

Time to actually push somewhere. Push your feature branch up: `git push -u origin feature/<your name>-new-functions`. The `-u` ties your local branch to that remote branch, so from now on plain `git push`/`git pull` on it know where to go without you spelling it out every time.

Pair up with your neighbor for this one. Have them `git fetch` and then `git switch feature/<your name>-new-functions` to pull your branch down onto their machine (or swap - either of you can drive).

Each of you pick a *different* not-yet-finished function (no need to collide on the same lines - we already did that dance in Module 3) and commit your change locally. Whoever pushes first gets through cleanly. The second person's push gets rejected:

```
 ! [rejected]        feature/<name>-new-functions -> feature/<name>-new-functions (fetch first)
error: failed to push some refs to '...'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally.
```

That's not a merge conflict - it's git refusing to let you push because your local branch is missing a commit the remote already has (your histories have diverged). Run `git pull` to fetch that commit and merge it into your branch. Since you each edited different functions, it merges cleanly with no conflict markers - run `git log --oneline --graph` afterward and you'll see both commits side by side, joined by a merge commit. Now push again - it'll go through.

### Working alone?

No neighbor? Simulate one with a second clone. From the directory *above* your existing clone:

```sh
git clone https://github.com/tpyle/git-training.git git-training-partner
```

This is a completely independent working copy - treat it as your "neighbor's machine" for the rest of this module (and for Module 8, if you're doing that one solo too). In it, run:

```sh
git fetch
git switch feature/<your name>-new-functions
```

Now play both parts, one at a time:

1. In your original clone (`git-training`), pick a not-yet-finished function, implement it, commit, then `git push`. This one goes through cleanly.
2. In `git-training-partner`, pick a *different* function, implement it, commit, then `git push`. This one gets rejected - same error as above, because `origin` has moved since you cloned/fetched it.
3. Still in `git-training-partner`, run `git pull` to bring in the other commit and merge it. Since you edited different functions, it's a clean merge - check `git log --oneline --graph`.
4. Push again from `git-training-partner` - it goes through.
5. Back in your original clone, `git pull` to catch up on the merge commit, so both clones agree.

Keep `git-training-partner` around if you're doing Module 8 solo too.

## Module 6: Finding the cause of bugs (`git blame`)

Not every bug announces itself with a compiler error. There's a commented-out test in [tests/test_stats.cpp](./tests/test_stats.cpp) - `PercentileTest.HundredthPercentile` - that calls `mathlib::percentile` with a percentile of exactly `100`. Uncomment it and rerun the suite (`ctest --test-dir build --output-on-failure`). Something's wrong - and until you uncommented it, nothing in the suite caught it.

Time to find out which commit is responsible. Run `git blame src/mathlib.cpp` - every line gets annotated with the commit that last touched it, plus who and when. Find the line doing the suspicious index math and note its commit hash.

`git show <hash>` pulls up that whole commit so you can see exactly what changed. Does the commit message match what the diff actually does?

For the fuller picture, `git log -p -- src/mathlib.cpp` walks the entire history of that one file, one diff at a time (`q` to quit the pager). You'll be able to watch `percentile` go from "doesn't support the 100th percentile yet" to "supports it, sort of" across two commits.

This is the real workflow for "who broke this, and why": reproduce it, `git blame` the suspicious line, `git show` the commit, and now you know exactly what to fix (and who to go ask about it).

## Module 7: Git Worktrees (`git worktree`)

Sometimes you want two branches checked out at once - maybe you're mid-change on your feature branch but need to quickly poke at `main`, without stashing anything.

From the repo root: `git worktree add ../git-training-scratch feature/<your name>-new-functions`. This checks that branch out into a brand new folder next to your existing clone - same repo, same history, independent working directory.

`cd ../git-training-scratch` and you've got a fully separate checkout to build, test, or edit in, while your original folder stays exactly as you left it.

`git worktree list` shows every worktree attached to this repo.

When you're done, clean up: `git worktree remove ../git-training-scratch` (git will refuse if there are uncommitted changes in there - commit them, stash them, or add `--force` if you really don't care).

## Module 8: Cherry-Picking (`git cherry-pick`)

Say your neighbor made one specific commit you want, but you don't want their whole branch.

Have them run `git log --oneline` on their branch and send you the hash of the commit you want.

On your own branch (`git switch feature/<your name>-new-functions`), run `git cherry-pick <hash>`. Git replays just that one commit's changes on top of whatever you've got checked out - you end up with a new commit (new hash, same content), the original is untouched.

If it applies cleanly, you're done. If it conflicts, you'll see the same conflict markers as Module 3 - fix them, `git add` the file, then `git cherry-pick --continue` (or `git cherry-pick --abort` if you'd rather bail out entirely).

### Working alone?

Use the `git-training-partner` clone from Module 5 (create it the same way described there if you skipped straight to this module).

1. In `git-training-partner`, pick a not-yet-finished function, implement it, and commit - but don't push it.
2. Grab its hash: `git log --oneline -1`.
3. Back in your original clone, add the partner clone as a temporary remote so you can see its commits without pushing anything to GitHub: `git remote add partner-sim ../git-training-partner && git fetch partner-sim`.
4. `git cherry-pick <hash>`, same as above.
5. Clean up the temporary remote once you're done: `git remote remove partner-sim`.

## Module 9: Opening a Pull Request

Everything so far has been local git, or a raw `git push`. A pull request (PR) is GitHub's layer on top of that: a request to merge one branch into another, with a place for discussion, automated checks, and required approvals before it's allowed to land.

Push your feature branch if you haven't already: `git push -u origin feature/<your name>-new-functions`.

Head to https://github.com/tpyle/git-training - you'll see a "Compare & pull request" banner for your branch. Click it (or go to the "Pull requests" tab → "New pull request" and pick `main` as base, your branch as compare), fill in a title/description, and click "Create pull request".

On the PR page, scroll down and you'll see a checks section - that's the CI workflow at `.github/workflows/ci.yml` running against your branch. Yellow dot while it's running, green check once it passes, red X if it fails.

Ask your neighbor to review it: send them the PR link, have them open the "Files changed" tab, click "Review changes" in the top right, and leave an approval (or request changes / just comment). You can also formally request their review yourself first, from the "Reviewers" gear icon in the sidebar.

Before either of those finish, notice the merge button is greyed out, with something like "Merging is blocked" / "Required statuses must pass" or "At least 1 approving review is required" underneath it. Once the check goes green and you've got an approval, watch that button light up.

**Don't actually click it.** Everyone in the room is working against this same repo and the same `main` - if every pair merges their PR, `main` turns into a pileup of unrelated changes and everyone's next rebase/pull gets a lot messier than intended. For this module, just get the PR to the "green check + approved + mergeable" state and leave it there (or close it without merging, if you want to tidy up).

*(Everything above can also be done from a terminal with the `gh` CLI, if you'd rather not leave the command line - `gh pr create`, `gh pr checks`, `gh pr review <number> --approve`.)*

Worth calling out: that gating - can't merge until the check passes and someone's approved - isn't something git or GitHub does automatically for every repo. It's a branch protection rule configured on this repo's `main` branch (already set up here), requiring the `CI / build-and-test` status check and at least one approving review before the merge button unlocks. Plenty of repos you'll work in elsewhere won't have this turned on at all - it's a deliberate setting, not a given.

### Working alone?

You can do everything through opening the PR and watching CI turn green by yourself. The review step is the one part that genuinely doesn't work solo: GitHub refuses to let you approve your own pull request, so the merge button will stay blocked on "review required" regardless of what you do locally. To see it actually unlock, ask Thomas or another participant to approve your PR; otherwise just note what the "Files changed" tab looks like from a reviewer's perspective and move on once CI is green.

# mathlib

A small, deliberately simple C++ math library used for training purposes
(practicing git workflows, PRs, and CI). It's not meant to be robust or
complete — poke at it, break it, fix it.

## Building and running tests

```sh
cmake -S . -B build
cmake --build build -j
ctest --test-dir build --output-on-failure
```

## Training exercises

A few functions are left unimplemented on purpose, and throw
`std::logic_error` if you call them:

* `mathlib::isPrime` — implement a primality check.
* `mathlib::gcd` — implement Euclid's algorithm (should return a
  non-negative result even for negative inputs). There's pseudocode for it
  in a comment in `mathlib.cpp`.
* `mathlib::lcm` — implement the least common multiple (needs
  `mathlib::gcd` working first).
* `mathlib::power` — works for non-negative exponents already; extend it to
  handle negative exponents too (e.g. `power(2.0, -2) == 0.25`).
* `mathlib::fibonacci` — implement the nth Fibonacci number, iteratively
  (there's pseudocode in `mathlib.cpp` - avoid the naive recursive version,
  it's exponentially slow).
* `mathlib::isPerfectSquare` — check whether a number is a perfect square,
  without using floating-point `sqrt()` (pseudocode in `mathlib.cpp`).

Each has a matching test in `tests/` that's currently named with a
`DISABLED_` prefix and already has the expected assertions written in.
Implement the function, remove the `DISABLED_` prefix from its test, and
confirm it passes.
