type Page = number;

interface FifoStep {
  page: Page;
  fault: boolean;
  frames: Page[];
  evicted?: Page;
}

interface FifoResult {
  frames: Page[];
  pageFaults: number;
  pageHits: number;
  steps: FifoStep[];
}

export function fifoPageReplacement(
  pages: Page[],
  frameCount: number,
): FifoResult {
  if (frameCount <= 0) {
    throw new Error("frameCount must be greater than 0");
  }

  const frames: Page[] = [];
  const queue: Page[] = [];
  const steps: FifoStep[] = [];

  let pageFaults = 0;
  let pageHits = 0;

  for (const page of pages) {
    const frameIndex = frames.indexOf(page);

    if (frameIndex !== -1) {
      pageHits += 1;
      steps.push({
        page,
        fault: false,
        frames: [...frames],
      });
      continue;
    }

    pageFaults += 1;

    if (frames.length === frameCount) {
      const evicted = queue.shift()!;
      const evictedIndex = frames.indexOf(evicted);
      frames.splice(evictedIndex, 1);

      steps.push({
        page,
        fault: true,
        frames: [...frames],
        evicted,
      });
    } else {
      steps.push({
        page,
        fault: true,
        frames: [...frames],
      });
    }

    frames.push(page);
    queue.push(page);

    steps[steps.length - 1].frames = [...frames];
  }

  return {
    frames: [...frames],
    pageFaults,
    pageHits,
    steps,
  };
}

// Example usage:
const pages = [1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5];
const result = fifoPageReplacement(pages, 3);

console.log("Page faults:", result.pageFaults);
console.log("Page hits:", result.pageHits);
console.log("Final frames:", result.frames);
console.log("Trace:", result.steps);